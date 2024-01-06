project('faze', 'cpp',
    default_options: ['cpp_std=c++17'],
    version:         '1.0.0',
    license:         'MIT',
)

smal = subproject('smal')

smal_header = smal.get_variable('smal_header')
smal_define = smal.get_variable('smal_define')

faze_header = include_directories('include')
faze_depend = [
    dependency('sfml-graphics', static: true),
]

executable('faze',
    sources: [
        'source/faze.cpp',
        'source/faze/Screen.cpp',
        'source/faze/ScreenManager.cpp',
        'source/faze/Engine.cpp',
        'source/faze/Maze.cpp',
        'source/faze/MazeScreen.cpp',
    ],
    include_directories: [faze_header, smal_header],
    dependencies:        [faze_depend],
    link_with:           [smal_define],
    link_args:           ['-lm'],
)
