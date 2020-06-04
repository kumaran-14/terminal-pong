project('ping-pong', 'cpp',
default_options : ['cpp_std=c++17'])

ncurses_dep = dependency('ncurses')
if not ncurses_dep.found()
  error('Dependency missing : Curses library not found')
endif

inc = include_directories('src/include')

pong_sources = ['src/ncurses.cpp',
               'src/screen.cpp',
               'src/window.cpp',
               'src/paddle.cpp',
               'src/ball.cpp',
               'src/inputHandler.cpp',
               'src/commands.cpp',
               'src/world.cpp',
               'src/game.cpp',
               'src/main.cpp']

executable('pong',
            pong_sources,
            include_directories : inc,
            dependencies: ncurses_dep)
