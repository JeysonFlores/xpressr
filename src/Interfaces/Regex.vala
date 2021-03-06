[DBus (name = "com.github.jeysonflores.Regex")]
interface Xpressr.Interfaces.Regex : Object {
    public abstract bool delete_regex (int id) throws GLib.Error;
    public abstract Xpressr.Models.Regex get_regex_by_id (int id) throws GLib.Error;
    public abstract Xpressr.Models.Regex[] get_regexes () throws GLib.Error;
    public abstract bool set_regex (string name, string regex, string example) throws GLib.Error;
    public abstract bool update_regex (int id, string name, string regex, string example) throws GLib.Error;

    public signal void regex_added (int id, string name, string regex, string example);
    public signal void regex_deleted (int id);
    public signal void regex_updated (int id, string name, string regex, string example);
}
