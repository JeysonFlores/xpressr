class Xpressr.MainWindow : Hdy.Window {

    private Xpressr.Interfaces.Regex regex_interface = null;

    public MainWindow (Gtk.Application application) {
        Object (
            application: application
        );
    }

    construct {
        Hdy.init ();

        var main_grid = new Gtk.Grid () {
            column_homogeneous = true,
            expand = true,
            orientation = Gtk.Orientation.VERTICAL
        };

        var header = new Xpressr.Widgets.HeaderBar ();

        var list_box = new Gtk.ListBox () {
            expand = true,
        };

        this.initialize_dbus (list_box);

        var scw = new Gtk.ScrolledWindow (null, null);
        scw.add (list_box);

        main_grid.add (header);
        main_grid.add (scw);

        this.add (main_grid);

        //TODO: This doesn't work (for some reason)
        this.regex_interface.regex_added.connect ((id, name, regex, example) => {
            Xpressr.Models.Regex new_regex_data = { id, name, regex, example };

            var new_regex = new Xpressr.Widgets.RegexItem (new_regex_data, this.regex_interface);

            list_box.insert (new_regex, 0);
        });
    }

    private void initialize_dbus (Gtk.ListBox list) {
        try {
            regex_interface = Bus.get_proxy_sync (BusType.SESSION, "com.github.jeysonflores.xpressrService",
                                                                "/com/github/jeysonflores/xpressrService/Regex");

            var regexes = regex_interface.get_regexes ();

            foreach (var regex in regexes) {
                var new_regex = new Xpressr.Widgets.RegexItem (regex, regex_interface);

                list.insert (new_regex, 0);
            }
        } catch (GLib.Error e) {
            warning ("⚠️ Error trying to connect to the DBus service: [%s]\n", e.message);
        }
    }
}
