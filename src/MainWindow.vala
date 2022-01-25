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
            activate_on_single_click = false,
            selection_mode = Gtk.SelectionMode.SINGLE,
            expand = true,
        };
        list_box.set_placeholder (new Gtk.Label ("No hay Regexes"));
        list_box.row_activated.connect ((row) => {
            print ("Row activated from outer scope\n");
        });

        list_box.row_selected.connect ((row) => {
            var regex_activated = row as Xpressr.Widgets.RegexItem;
            print (regex_activated.regex.name);
            print ("\n");
            print (regex_activated.regex.regex);
            print ("\n");
            print ("Row selected from outer scope\n");
        });

        this.initialize_dbus (list_box);

        var scw = new Gtk.ScrolledWindow (null, null);
        scw.add (list_box);

        main_grid.add (header);
        main_grid.add (scw);

        this.add (main_grid);

        this.regex_interface.regex_added.connect ((id, name, regex, example) => {
            Xpressr.Models.Regex new_regex_data = { id, name, regex, example };

            var new_regex = new Xpressr.Widgets.RegexItem (new_regex_data, this.regex_interface);

            list_box.insert (new_regex, -1);
            list_box.show_all ();
        });
    }

    private void initialize_dbus (Gtk.ListBox list) {
        try {
            regex_interface = Bus.get_proxy_sync (BusType.SESSION, "com.github.jeysonflores.xpressrService",
                                                                "/com/github/jeysonflores/xpressrService/Regex");

            var regexes = regex_interface.get_regexes ();

            foreach (var regex in regexes) {
                var new_regex = new Xpressr.Widgets.RegexItem (regex, regex_interface);
                new_regex.popover_opened.connect ((row) => {
                    list.select_row (row);
                });

                list.insert (new_regex, 0);
            }
        } catch (GLib.Error e) {
            warning ("⚠️ Error trying to connect to the DBus service: [%s]\n", e.message);
        }
    }
}
