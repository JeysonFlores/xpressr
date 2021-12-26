project('com.github.jeysonflores.xpressr', ['vala', 'c'],
    version: '0.1.2',
    license: 'GPL-3.0'
)

add_project_arguments(
    '-DGETTEXT_PACKAGE="@0@"'.format(meson.project_name()),
    language: 'c'
)

conf = configuration_data()
conf.set_quoted('GETTEXT_PACKAGE', meson.project_name())
configure_file(output: 'config.h', configuration: conf)
config_h_dir = include_directories('.')

c_args = [
  '-include', 'config.h'
]

executable(
    'com.github.jeysonflores.switcher',
    'src/Xpressr.vala',
    c_args: c_args,
    dependencies: [
        dependency('glib-2.0'),
        dependency('gobject-2.0'),
        dependency('granite'),
        dependency('gtk+-3.0'),
        dependency('gdk-pixbuf-2.0'),
        dependency('libhandy-1', version: '>= 0.90.0'),
    ],
    install : true
)

