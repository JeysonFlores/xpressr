class Xpressr.Widgets.RegexItem : Gtk.ListBoxRow {

    public Xpressr.Models.Regex regex { get; construct; }
    public Xpressr.Interfaces.Regex iface { get; construct; }

    public RegexItem (Xpressr.Models.Regex regex, Xpressr.Interfaces.Regex iface) {
        Object (
            regex: regex,
            iface: iface,
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

        var name_label = new Gtk.Label (this.regex.name) {
            ellipsize = Pango.EllipsizeMode.END
        };
        name_label.get_style_context ().add_class ("h2");

        var regex_label = new Gtk.Label (this.regex.regex) {
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

        this.iface.regex_updated.connect ((id, name, regex, example) => {
            if (id == this.regex.id) {
                this.regex.name = name;
                this.regex.regex = regex;
                this.regex.example = example;

                name_label.label = name;
                regex_label.label = regex;
            }
        });

        this.iface.regex_deleted.connect ((id) => {
            if (id == this.regex.id) {
                this.destroy ();
            }
        });
    }
}
