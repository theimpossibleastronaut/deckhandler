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
swig_src = [c_source, src]

if swig_lang == 'python'
	shared_library(
		meson.project_name(),
		[swig_src],
		name_prefix: '_',
		include_directories: include_directories('..'),
		dependencies: python)
elif swig_lang == 'php7'
	myphp = find_program('php-config')
	php_includes = run_command(myphp, '--includes')
	shared_library(
		meson.project_name(),
		[swig_src],
		c_args: php_includes.stdout().strip(),
		name_prefix: '_',
		include_directories: include_directories('..')
		)
endif

