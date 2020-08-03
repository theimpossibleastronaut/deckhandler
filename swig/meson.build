swig = find_program('swig')
swig_gen = generator(
	swig,
	output: ['@BASENAME@_wrap.c'],
	arguments: ['-' + swig_lang,
	'-o', './@OUTPUT@',
	'-outdir', meson.current_build_dir(),
	'-I' + meson.source_root(),
	'@INPUT@'])

i_source = join_paths(meson.current_source_dir(), meson.project_name() + '.i')
c_source = swig_gen.process(i_source)

dep =
if swig_lang == 'python'
	dep = dependency('python')
endif

swig_src = [c_source, src]
shared_library(
	meson.project_name(),
	[swig_src],
	name_prefix: '_',
	include_directories: include_directories('..'),
	dependencies: dep)
