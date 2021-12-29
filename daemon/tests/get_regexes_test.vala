
struct Bar {
    public int id;
    public string name; 
    public string regex; 
    public string example;
}

[DBus (name = "com.github.jeysonflores.Regex")]
interface DemoDbus.DbusDemo : Object {
    public abstract bool delete_regex (int id) throws GLib.Error;
    public abstract Bar get_regex_by_id (int id) throws GLib.Error;
    public abstract Bar[] get_regexes () throws GLib.Error;
}

public class DemoDbus.Example {

    private DbusDemo dbdemo = null;

    public Example () {

        try {
            dbdemo = Bus.get_proxy_sync (BusType.SESSION, "com.github.jeysonflores.xpressrService",
                                                            "/com/github/jeysonflores/xpressrService/Regex");          
            var regexes = dbdemo.get_regexes();
            print("Vala test \n \n");
            foreach (var regex in regexes)
            {
                print("Id : ");
                print(regex.id.to_string ());
                print("\n");
                print("Name : ");
                print(regex.name);
                print("\n");
                print("Regex : ");
                print(regex.regex);
                print("\n");
                print("Example : ");
                print(regex.example);
                print("\n\n");
            }
        } catch (GLib.Error e) {
            warning ("Error al conectar a DBUS [%s]\n", e.message);
        }
    }
}

int main (string[] args) {
    var win = new DemoDbus.Example ();
    return 0;
}