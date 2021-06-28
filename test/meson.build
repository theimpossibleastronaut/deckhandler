exe = executable(
  'test_01',
  'test_01.c',
  include_directories : '..',
  link_with: buildtarget.get_static_lib()
)

test('test_01', exe)

vg = find_program('valgrind', required : false)
if vg.found()
add_test_setup('valgrind',
  exe_wrapper : [vg, '--error-exitcode=1', '--leak-check=full'],
  )
endif
