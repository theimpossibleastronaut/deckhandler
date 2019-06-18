project('deckhandler', 'c')
src = ('deckhandler.c')
shared_library(meson.project_name(), src)
default_lib = static_library(meson.project_name(), src)
executable('example-01', 'example-01.c', link_with : default_lib)

