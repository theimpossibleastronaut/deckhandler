project(
  'deckhandler',
  'c',
  version: '0.1.0999',
  default_options: [
    'warning_level=3',
    'b_sanitize=address,undefined',
    'b_lundef=false']
  )
add_global_arguments = [
  '-fno-common',
  '-fanalyzer'
  ]

buildtarget = library(
  meson.project_name(),
  'deckhandler.c',
  version : meson.project_version(),
  install: not meson.is_subproject()
  )

# How to use in a superproject and other info
# https://mesonbuild.com/Subprojects.html
deckhandler_dep = declare_dependency(link_with : buildtarget)

if not meson.is_subproject()
  pkg = import('pkgconfig')
  pkg.generate(
    buildtarget,
    description : 'Library to handle a deck of cards')

  install_headers('deckhandler.h')
  subdir('test')

#  install_subdir(
#  join_paths('docs'),
#  install_dir : join_paths(get_option('docdir'), 'html'),
#  strip_directory : true
#  )

#  install_data(files(
#    'LICENSE',
#    'README.md',
#    'SWIG_INTERFACE.md'
#    ),
#    install_dir : get_option('docdir'))
endif

swig_lang = get_option('swig_lang')
if swig_lang != ''
  subdir('swig')
endif
