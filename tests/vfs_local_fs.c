#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <vfs.h>
#include <vfs_file.h>

#include "vfs_local_fs.h"

static vfs_h* get_vfs(const char* proto, const char* uri) {

  vfs_config* conf = malloc(sizeof(vfs_config));
  assert_non_null(conf);

  if (proto) {
    snprintf(conf->proto, sizeof(conf->proto), "%s", proto);
  }
  else {
    snprintf(conf->proto, sizeof(conf->proto), "%s", "local");
  }

  if (uri) {
    snprintf(conf->uri, sizeof(conf->uri), "%s", uri);
  }
  else {
    snprintf(conf->uri, sizeof(conf->uri), "%s", "/dev/shm");
  }

  vfs_error err;
  vfs_h* vfs = vfs_new(conf, &err);

  assert_non_null(vfs);
  assert_non_null(vfs->open);
  assert_non_null(vfs->close);
  assert_non_null(vfs->get_files);

  return vfs;
}

// //////////////////////////////////////////////////////////////////////////

extern void test_vfs_local_fs_open() {

  // local:///dev/shm
  // ftp://127.0.0.1@utest:ptest
  // RANDOM_STRING

  vfs_h* vfs = get_vfs("local", "/dev/shm");
  int ret = vfs->open(vfs);
  
  vfs_close(&vfs);

  assert_true(ret == 0);
}

extern void test_vfs_local_fs_get_files() {

  vfs_h* vfs = get_vfs("local", "/dev/shm");
  vfs->open(vfs);

  vfs_error err;
  vfs_file_search_result* result = vfs->get_files(vfs, NULL, &err);

  assert_non_null(result);
  assert_non_null(result->files);
  assert_true(result->n_items > 0);
  assert_true(err == E_NO_ERR);
  
  vfs_file_search_result_free(&result);

  assert_null(result);

  vfs_close(&vfs);
}

extern void test_vfs_local_fs_get_txt_files() {

  vfs_h* vfs = get_vfs("local", "/dev/shm");
  vfs->open(vfs);

  vfs_error err;
  vfs_file_search_result* result = vfs->get_files(vfs, "*.txt", &err);

  assert_non_null(result);
  assert_non_null(result->files);
  assert_true(result->n_items > 0);
  assert_true(err == E_NO_ERR);  

  vfs_file_search_result_free(&result);

  assert_null(result);
  
  vfs_close(&vfs);
}
