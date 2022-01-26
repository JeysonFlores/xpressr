class Xpressr.Views.ListView : Gtk.Grid {

    public Xpressr.Interfaces.Regex? regex_interface { get; construct; }
    public signal void create_new_regex ();
    public signal void edit_regex (Xpressr.Models.Regex regex);

    public ListView (Xpressr.Interfaces.Regex iface) {
        Object (
            regex_interface: iface
        );
    }

    construct {
        this.column_homogeneous = true;
        this.expand = true;
        this.orientation = Gtk.Orientation.VERTICAL;
        /* Header construction */
        var left_header = new Hdy.HeaderBar () {
            decoration_layout = "close:",
            has_subtitle = false,
            show_close_button = true,
            can_focus = false
        };
        left_header.get_style_context ().add_class ("flat");

        var add_button = new Gtk.Button.with_label ("Add Regex") {
            image = new Gtk.Image.from_icon_name ("ionicons-add-circle-symbolic", Gtk.IconSize.BUTTON),
            always_show_image = true,
            halign = Gtk.Align.END,
            hexpand = true
        };
        add_button.get_style_context ().add_class ("suggested-action");

        var right_header = new Hdy.HeaderBar () {
            custom_title = add_button,
            decoration_layout = "",
            has_subtitle = false,
            can_focus = false,
        };
        right_header.get_style_context ().add_class ("flat");

        var header_grid = new Gtk.Grid () {
            column_homogeneous = true,
            hexpand = true,
            orientation = Gtk.Orientation.HORIZONTAL
        };

        header_grid.add (left_header);
        header_grid.add (right_header);

        header_grid.get_style_context ().add_class ("header-background");

        this.add (header_grid);

        /* Body construction */
        var list_box = new Gtk.ListBox () {
            activate_on_single_click = false,
            selection_mode = Gtk.SelectionMode.SINGLE,
            expand = true,
        };
        list_box.set_placeholder (new Gtk.Label ("No hay Regexes"));

        try {
            var regexes = this.regex_interface.get_regexes ();

            foreach (var regex in regexes) {
                var new_regex = new Xpressr.Widgets.RegexItem (regex, regex_interface);
                new_regex.regex_copied.connect ((row) => {
                    list_box.select_row (row);
                });

                list_box.insert (new_regex, 0);
            }
        } catch (GLib.Error e) {
            warning ("⚠️ Error trying to connect to the DBus service: [%s]\n", e.message);
        }

        var scw = new Gtk.ScrolledWindow (null, null);
        scw.add (list_box);

        this.add (scw);

        /* Signal handling */
        add_button.clicked.connect (() => {
            this.create_new_regex ();
        });

        list_box.row_activated.connect ((row) => {
            var regex_activated = row as Xpressr.Widgets.RegexItem;
            this.edit_regex (regex_activated.regex);
        });

        this.regex_interface.regex_added.connect ((id, name, regex, example) => {
            Xpressr.Models.Regex new_regex_data = { id, name, regex, example };

            var new_regex = new Xpressr.Widgets.RegexItem (new_regex_data, this.regex_interface);

            list_box.insert (new_regex, -1);
            list_box.show_all ();
        });

    }
}