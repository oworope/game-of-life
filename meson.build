project('game-of-life', 'cpp',
  default_options: 'default_library=static',
  version: '0.1.0')

src = [
  'src/main.cpp',
]

incl_dir = include_directories('include')

sdl2_dep = dependency('sdl2')
sdl2main_dep = dependency('sdl2main')

executable('game-of-life', src,
  win_subsystem: 'windows',
  dependencies: [sdl2_dep, sdl2main_dep],
  include_directories: incl_dir)
