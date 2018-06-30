
#include <stdio.h>

#include <vfs.h>
#include <vfs_local_fs.h>

extern int vfs_local_fs_open(const vfs_h* vfs) {

  return 0;
}

extern int vfs_local_fs_close(const vfs_h* vfs) {

  return 0;
}

extern vfs_file_search_result* vfs_local_fs_get_files(const vfs_h* vfs, const char* pattern) {

  // printf("uri => %s\n", vfs->config->uri);
  
  return NULL;
}
