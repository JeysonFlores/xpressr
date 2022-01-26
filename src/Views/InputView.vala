class Xpressr.Views.InputView : Gtk.Grid {

    public bool edit_mode { get; construct; }
    public Xpressr.Interfaces.Regex? regex_interface { get; construct; }
    public Xpressr.Models.Regex? regex { get; set; }

    public InputView (Xpressr.Interfaces.Regex iface) {
        Object(
            edit_mode: false,
            regex_interface: iface
        );
    }

    public InputView.for_editing (Xpressr.Interfaces.Regex iface) {
        Object (
            edit_mode: true,
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

        var add_button = new Gtk.Button.with_label ("Save") {
            image = new Gtk.Image.from_icon_name ("document-save-symbolic", Gtk.IconSize.BUTTON),
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

        this.add (header_grid);

        /* Body construction */
        var main_grid = new Gtk.Grid () {
            column_homogeneous = true,
            hexpand = true,
            orientation = Gtk.Orientation.VERTICAL,
            halign = Gtk.Align.CENTER
        };

        Gtk.Label title;

        if (this.edit_mode)
            title = new Gtk.Label ("Edit the regex") {
                margin_bottom = 10
            };
        else
            title = new Gtk.Label ("Set up the regex") {
                margin_bottom = 10
            };
        title.get_style_context ().add_class ("h2");

        var name_label = new Gtk.Label ("Name") {
            halign = Gtk.Align.START
        };
        name_label.get_style_context ().add_class ("h4");
        var name_entry = new Granite.ValidatedEntry () {
            margin_bottom = 7
        };

        var regex_label = new Gtk.Label ("Regex") {
            halign = Gtk.Align.START
        };
        regex_label.get_style_context ().add_class ("h4");
        var regex_entry = new Granite.ValidatedEntry () {
            margin_bottom = 7
        };

        var example_label = new Gtk.Label ("Example") {
            halign = Gtk.Align.START
        };
        example_label.get_style_context ().add_class ("h4");
        var example_entry = new Granite.ValidatedEntry () {
            margin_bottom = 7
        };

        main_grid.add (title);
        main_grid.add (name_label);
        main_grid.add (name_entry);
        main_grid.add (regex_label);
        main_grid.add (regex_entry);
        main_grid.add (example_label);
        main_grid.add (example_entry);

        var scw = new Gtk.ScrolledWindow (null, null) {
            expand = true
        };
        scw.add (main_grid);

        this.add (scw);

        /* Signal handling */
        this.notify["regex"].connect(() => {
            name_entry.set_text (this.regex.name);
            regex_entry.set_text (this.regex.regex);
            example_entry.set_text (this.regex.example);
        });
        
        GLib.Regex regex_matcher;
        regex_entry.changed.connect (() => {
            try{
                regex_matcher = new GLib.Regex (regex_entry.get_text (), 0, 0);
                example_entry.regex = regex_matcher;
                this.check_validity (example_entry);
            } catch (GLib.RegexError e) {
                print ("xd");
            }
        });

        regex_entry.paste_clipboard.connect (() => {
            try{
                regex_matcher = new GLib.Regex (regex_entry.get_text (), 0, 0);
                example_entry.regex = regex_matcher;
                this.check_validity (example_entry);
            } catch (GLib.RegexError e) {
                print ("xd");
            }
        });
    }

    private void check_validity (Granite.ValidatedEntry entry) {
        if (entry.is_valid && entry.regex != null) {
            entry.is_valid = entry.regex.match (entry.text);
        }
    }
}