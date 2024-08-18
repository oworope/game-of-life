project('game-of-life', 'cpp',
  default_options: 'default_library=static',
  version: '1.0.0')

src = [
  'src/main.cpp',
  'src/application.cpp'
]

incl_dir = include_directories('include')

sfml_dep = dependency('sfml')

executable('game-of-life', src,
  win_subsystem: 'windows',
  dependencies: sfml_dep,
  include_directories: incl_dir)
