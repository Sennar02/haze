project('faze', 'cpp',
    default_options: ['cpp_std=c++17'],
    version:         '1.0.0',
    license:         'MIT',
)

smal = subproject('smal')

smal_depend = smal.get_variable('smal_depend')
smal_define = smal.get_variable('smal_define')
smal_header = smal.get_variable('smal_header')

faze_header = include_directories('include')

faze_depend = [
    dependency('sfml-graphics', static: true),
]

executable('faze',
    sources: [
        'source/faze.cpp',
        'source/faze/Engine.cpp',
        'source/faze/Screen.cpp',
        'source/faze/TitleScreen.cpp',
    ],
    include_directories: [smal_header, faze_header],
    link_with:           [smal_define],
    link_args:           ['-lm'],
    dependencies:        [faze_depend],
)
