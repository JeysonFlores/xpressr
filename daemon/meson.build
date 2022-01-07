project('com.github.jeysonflores.xpressrService', ['cpp', 'c'], 
          version: '0.1.0',
    meson_version: '>= 0.50.0',
  default_options: [ 'warning_level=2',
                     'cpp_std=gnu++17',
                   ],
)

install_data(
    'data/' + meson.project_name() + '.service',
    install_dir: join_paths(get_option('datadir'), 'dbus-1/services')
)

executable(
      meson.project_name(),
      ['src/XpressrService.cpp'],
      ['src/Adaptors/Regex.h'],
      ['src/Interfaces/Regex.h', 'src/Interfaces/Regex.cpp'],
      ['src/Services/DataManager.h', 'src/Services/DataManager.cpp'],
      ['src/Utils/Logger.h', 'src/Utils/Logger.cpp'], 
      dependencies: [
        dependency('sdbus-c++'),
        dependency('sqlite_modern_cpp'),
      ],
      install: true
)
