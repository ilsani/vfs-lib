#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <vfs.h>
#include <vfs_file.h>

#include "vfs_ftp.h"

/* static vfs_h* get_vfs(const char* proto, */
/* 		      const char* uri, */
/* 		      const char* username, */
/* 		      const char* password) { */

/*   vfs_config* conf = malloc(sizeof(vfs_config)); */
/*   assert_non_null(conf); */

/*   snprintf(conf->proto, sizeof(conf->proto), "%s", "ftp"); */
/*   snprintf(conf->uri, sizeof(conf->uri), "%s", "127.0.0.1"); */
/*   /\* snprintf(conf->username, sizeof(conf->username), "%s", username); *\/ */
/*   /\* snprintf(conf->password, sizeof(conf->password), "%s", password); *\/ */

/*   vfs_error err; */
/*   vfs_h* vfs = vfs_new(conf, &err); */

/*   assert_non_null(vfs); */
/*   assert_non_null(vfs->open); */
/*   assert_non_null(vfs->close); */
/*   assert_non_null(vfs->get_files); */

/*   return vfs; */
/* } */

// //////////////////////////////////////////////////////////////////////////

extern void test_vfs_ftp_open() {
}

extern void test_vfs_ftp_get_files() {

  /* vfs_h* vfs = get_vfs(NULL, NULL, NULL, NULL); */
  /* vfs->open(vfs); */

  /* vfs_error err; */
  /* vfs_file_search_result* result = vfs->get_files(vfs, NULL, &err); */
  
  /* assert_non_null(result); */
  /* assert_non_null(result->files); */
  /* assert_true(result->n_items > 0); */
  /* assert_true(err == E_NO_ERR); */
  
  /* vfs_file_search_result_free(&result); */

  /* assert_null(result); */

  /* vfs_close(&vfs); */
}
