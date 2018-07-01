
#include <vfs.h>
#include <vfs_ftp.h>
#include <vfs_file.h>

extern int vfs_ftp_open(const vfs_h* vfs) {

  return 0;
}

extern int vfs_ftp_close(const vfs_h* vfs) {

  return 0;
}

extern vfs_file_search_result* vfs_ftp_get_files(const vfs_h* vfs,
						 const char* pattern,
						 vfs_error* error) {
  return NULL;
}












