project('deckhandler', 'c', version: '0.0.1')
src = ('deckhandler.c')
shared_library(
	meson.project_name(),
	src,
	version : meson.project_version(),
	soversion : '0',
	install: true)
default_lib = static_library(meson.project_name(), src, install:true)
executable('example-01', 'example-01.c', link_with : default_lib)

pkgconf = configuration_data()
pkgconf.set('VERSION', meson.project_version())
pkgconf.set('prefix', get_option('prefix'))
pkgconf.set('libdir', get_option('libdir'))
pkgconf.set('includedir', get_option('includedir'))

configure_file(
	input : 'deckhandler.pc.in',
	output : 'deckhandler.pc',
	configuration : pkgconf)

install_headers('deckhandler.h')

