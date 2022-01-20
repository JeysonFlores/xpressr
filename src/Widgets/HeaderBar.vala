class Xpressr.Widgets.HeaderBar : Gtk.Grid {

    public HeaderBar () {
        Object ();
    }

    construct {
        var left_header = new Hdy.HeaderBar () {
            decoration_layout = "close:",
            has_subtitle = false,
            show_close_button = true,
            can_focus = false
        };
        left_header.get_style_context ().add_class ("flat");

        var add_button = new Gtk.Button.with_label ("Add Regex") {
            image = new Gtk.Image.from_icon_name ("insert-object-symbolic", Gtk.IconSize.BUTTON),
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

        var title_box = new Gtk.Grid () {
            column_homogeneous = true,
            hexpand = true,
            orientation = Gtk.Orientation.HORIZONTAL
        };

        title_box.add (left_header);
        title_box.add (right_header);

        this.add (title_box);
    }
}