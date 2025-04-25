swig = find_program('swig')
swig_gen = generator(
  swig,
  output: ['@BASENAME@_wrap.c'],
  arguments: [
    '-' + swig_lang,
    '-o',
    './@OUTPUT@',
    '-outdir',
    meson.current_build_dir(),
    '-I' + meson.project_source_root(),
    '@INPUT@',
  ],
)

i_source = meson.project_name() + '.i'
c_source = swig_gen.process(i_source)

python_dep = []
if swig_lang == 'python'
  python = import('python')
  py_installation = python.find_installation()
  python_dep = py_installation.dependency(embed: true)
endif

mathlib = cc.find_library('m', required: true)

swig_src = [c_source, src]
shared_library(
  meson.project_name(),
  [swig_src],
  name_prefix: '_',
  dependencies: [
    python_dep,
    mathlib,
    deckhandler_dep,
  ],
)
