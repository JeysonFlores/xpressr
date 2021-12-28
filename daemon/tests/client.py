import gi
gi.require_version('Gtk', '3.0')

from gi.repository import Gtk
import dbus

def main():
    bus = dbus.SessionBus()

    remote_object = bus.get_object("com.github.jeysonflores.xpressrService", "/com/github/jeysonflores/xpressrService/Regex")

    iface = dbus.Interface(remote_object, "com.github.jeysonflores.Regex")

    regexes = iface.GetRegexes()

    for regex in regexes:
        print("Id: " + str(regex[0]))
        print("Name: " + str(regex[1]))
        print("Regex: " + str(regex[2]))
        print("Example: " + str(regex[3]))
        print("\n")

if __name__ == '__main__':
    main()