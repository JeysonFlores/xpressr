[DBus (name = "com.github.jeysonflores.Regex")]
interface Xpressr.Interfaces.Regex : Object {
    public abstract bool delete_regex (int id) throws GLib.Error;
    public abstract Xpressr.Models.Regex get_regex_by_id (int id) throws GLib.Error;
    public abstract Xpressr.Models.Regex[] get_regexes () throws GLib.Error;
}
