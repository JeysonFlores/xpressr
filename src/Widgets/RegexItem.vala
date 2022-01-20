class Xpressr.Widgets.RegexItem : Gtk.ListBoxRow {

    public string regex_name { get; construct; }
    public string regex { get; construct; }

    public RegexItem (string name, string regex) {
        Object (
            regex_name: name,
            regex: regex,
            margin_bottom: 5,
            margin_top: 5
        );
    }

    construct {
        var upper_box = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 0) {
            margin_left = 10,
            margin_right = 10
        };

        var inner_box = new Gtk.Box (Gtk.Orientation.VERTICAL, 5) {
            hexpand = true
        };

        var name_label = new Gtk.Label (this.regex_name) {
            ellipsize = Pango.EllipsizeMode.END
        };
        name_label.get_style_context ().add_class ("h2");

        var regex_label = new Gtk.Label (this.regex) {
            ellipsize = Pango.EllipsizeMode.END,
            margin_bottom = 5
        };
        regex_label.get_style_context ().add_class ("h3");
        regex_label.get_style_context ().add_class ("dim-label");

        inner_box.pack_start (name_label, true, true, 0);
        inner_box.pack_start (regex_label, true, true, 0);

        var copy_button = new Gtk.Button.from_icon_name ("edit-copy-symbolic", Gtk.IconSize.BUTTON) {
            can_focus = false
        };
        copy_button.get_style_context ().add_class ("flat");

        upper_box.pack_start (inner_box, true, true, 0);
        upper_box.pack_start (copy_button, true, true, 0);

        this.add (upper_box);
    }
}
