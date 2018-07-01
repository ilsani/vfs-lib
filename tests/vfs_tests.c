
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <vfs.h>

#include "vfs_local_fs.h"
#include "vfs_ftp.h"

int main(void) {

  const struct CMUnitTest tests[] = {

    // Local FS
    cmocka_unit_test(test_vfs_local_fs_open),
    cmocka_unit_test(test_vfs_local_fs_get_files),
    cmocka_unit_test(test_vfs_local_fs_get_txt_files),

    // FTP FS
    cmocka_unit_test(test_vfs_ftp_open),
    cmocka_unit_test(test_vfs_ftp_get_files),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
