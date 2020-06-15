project('deckhandler', 'c', version: '0.0.1')
src = (meson.source_root() / 'deckhandler.c')
buildtarget = both_libraries(
	meson.project_name(),
	src,
	version : meson.project_version(),
	soversion : '0',
	install: true)

extra_args = ['-fno-common']

executable('example-01', 'example-01.c', c_args : extra_args, link_with : buildtarget.get_static_lib())

pkg = import('pkgconfig')
pkg.generate(
	buildtarget,
	description : 'Library to handle a deck of cards')

install_headers('deckhandler.h')

swig_lang = get_option('swig_lang')
if swig_lang != ''
	subdir('swig')
endif
