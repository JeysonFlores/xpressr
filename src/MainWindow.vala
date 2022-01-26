class Xpressr.MainWindow : Hdy.Window {

    private Xpressr.Interfaces.Regex regex_interface = null;

    public MainWindow (Gtk.Application application) {
        Object (
            application: application
        );
    }

    construct {
        Hdy.init ();

        this.initialize_dbus ();

        var deck = new Hdy.Deck () {
            can_swipe_back = true,
            can_swipe_forward = false,
            vhomogeneous = true,
            hhomogeneous = true,
            expand = true,
            transition_type = Hdy.DeckTransitionType.OVER
        };

        var list_view = new Xpressr.Views.ListView (this.regex_interface);
        var add_new_view = new Xpressr.Views.InputView (this.regex_interface);
        var edit_view = new Xpressr.Views.InputView.for_editing (this.regex_interface);

        deck.add (list_view);
        deck.add (add_new_view);
        deck.add (edit_view);

        /*deck.notify["transition-running"].connect (() => {
            if (!deck.transition_running) {
                if(deck.visible_child == color_picker_view)
                    icon_mode.set_active (0);

                if(deck.visible_child == label2)
                    icon_mode.set_active (1);

                if(deck.visible_child == label3)
                    icon_mode.set_active (2);

                if(deck.visible_child == label4)
                    icon_mode.set_active (3);
            }
        });*/

        this.add (deck);

        list_view.create_new_regex.connect (() => {
            deck.reorder_child_after (add_new_view, list_view);
            deck.visible_child = add_new_view;
        });

        list_view.edit_regex.connect ((model) => {
            edit_view.regex = model;
            deck.reorder_child_after (edit_view, list_view);
            deck.visible_child = edit_view;
        });
    }

    private void initialize_dbus () {
        try {
            regex_interface = Bus.get_proxy_sync (BusType.SESSION, "com.github.jeysonflores.xpressrService",
                                                                "/com/github/jeysonflores/xpressrService/Regex");        } catch (GLib.Error e) {
            warning ("⚠️ Error trying to connect to the DBus service: [%s]\n", e.message);
        }
    }
}
