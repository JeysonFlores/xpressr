add_rules("mode.release", "mode.debug")

add_requires("gtk+3", "glib")

target("get_regexes_test")
    set_kind("binary")
    add_rules("vala")
    add_files("get_regexes_test.vala")
    add_packages("gtk+3", "glib")
    add_values("vala.packages", "gtk+-3.0")