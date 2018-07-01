#ifndef VFS_LOCAL_FS_H
#define VFS_LOCAL_FS_H

#include <vfs.h>

extern int vfs_local_fs_open(const vfs_h* vfs);
extern int vfs_local_fs_close(const vfs_h* vfs);
extern vfs_file_search_result* vfs_local_fs_get_files(const vfs_h* vfs, const char* pattern, vfs_error* error);

#endif // VFS_LOCAL_FS_H
