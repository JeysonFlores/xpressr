project('com.github.jeysonflores.xpressrService', ['cpp', 'c'], 
          version: '0.1.0',
    meson_version: '>= 0.50.0',
  default_options: [ 'warning_level=2',
                     'cpp_std=gnu++17',
                   ],
)


executable(
	meson.project_name(),
	['src/XpressrService.cpp'],
  ['src/Adaptors/Regex.h'],
  ['src/Interfaces/Regex.h', 'src/Interfaces/Regex.cpp'], 
  ['src/Utils/Logger.h'], 
	dependencies: [
		dependency('sdbus-c++'),
	],
	install: true
)
