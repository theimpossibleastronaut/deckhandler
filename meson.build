project('deckhandler', 'c', version: '0.0.1')
add_global_arguments = [
  '-fno-common',
  '-fanalyzer'
  ]
src = (meson.source_root() / 'deckhandler.c')

buildtarget = library(
  meson.project_name(),
  src,
  version : meson.project_version(),
  soversion : '0',
  install: true)

subdir('test')

pkg = import('pkgconfig')
pkg.generate(
  buildtarget,
  description : 'Library to handle a deck of cards')

install_headers('deckhandler.h')

swig_lang = get_option('swig_lang')
if swig_lang != ''
  subdir('swig')
endif
