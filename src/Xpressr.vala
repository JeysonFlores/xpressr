public class Xpressr.Application : Gtk.Application {
    public Application () {
        Object (
            application_id: "com.github.jeysonflores.xpressr",
            flags: ApplicationFlags.FLAGS_NONE
        );
    }

    protected override void activate () {
        var main_window = new Xpressr.MainWindow (this);
        main_window.show_all ();
    }

    public static int main (string[] args) {
        return new Application ().run (args);
    }
}