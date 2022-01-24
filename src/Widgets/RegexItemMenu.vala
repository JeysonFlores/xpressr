class Xpressr.Widgets.RegexItemMenu : Gtk.Popover {

    public Xpressr.Widgets.RegexItem item { get; construct ; }

    public RegexItemMenu (Gtk.Widget origin, Xpressr.Widgets.RegexItem data) {
        Object (
            relative_to: origin,
            item: data
        );
    }

    construct {
        var layout = new Gtk.Grid () {
            orientation = Gtk.Orientation.VERTICAL,
            margin = 12,
            column_spacing = 12,
            row_spacing = 6
        };

        var copy_regex_button = new Gtk.Button () {
            can_focus = false
        };
        copy_regex_button.get_child ().destroy ();
        copy_regex_button.add (new Granite.AccelLabel ("Copy to clipboard", "<Ctrl>C"));
        copy_regex_button.get_style_context ().add_class ("flat");

        var delete_regex_button = new Gtk.Button () {
            can_focus = false
        };
        delete_regex_button.get_child ().destroy ();
        delete_regex_button.add (new Granite.AccelLabel ("Delete", "<Ctrl>D"));
        delete_regex_button.get_style_context ().add_class ("flat");

        layout.add (copy_regex_button);
        layout.add (new Gtk.Separator (Gtk.Orientation.VERTICAL));
        layout.add (delete_regex_button);

        this.add (layout);

        var clipboard = Gtk.Clipboard.get (Gdk.SELECTION_CLIPBOARD);
        copy_regex_button.clicked.connect (() => {
            clipboard.set_text (this.item.regex.regex, -1);
            this.destroy ();
        });

        delete_regex_button.clicked.connect (() => {
            try {
                this.item.iface.delete_regex (this.item.regex.id);
            } catch (GLib.Error e) {
                warning ("⚠️ Error trying delete the given regex: [%s]\n", e.message);
            }
        });
    }
}
