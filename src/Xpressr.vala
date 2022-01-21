public class Xpressr.Application : Gtk.Application {
    public Application () {
        Object (
            application_id: "com.github.jeysonflores.xpressr",
            flags: ApplicationFlags.FLAGS_NONE
        );
    }

    protected override void activate () {
        var granite_settings = Granite.Settings.get_default ();
        var gtk_settings = Gtk.Settings.get_default ();

        gtk_settings.gtk_application_prefer_dark_theme = (
            granite_settings.prefers_color_scheme == Granite.Settings.ColorScheme.DARK
        );

        var main_window = new Xpressr.MainWindow (this);
        main_window.show_all ();
    }

    public static int main (string[] args) {
        return new Application ().run (args);
    }
}
