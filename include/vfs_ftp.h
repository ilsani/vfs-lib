#ifndef VFS_FTP_H
#define VFS_FTP_H

#include <vfs.h>

extern int vfs_ftp_open(const vfs_h* vfs);
extern int vfs_ftp_close(const vfs_h* vfs);
extern vfs_file_search_result* vfs_ftp_get_files(const vfs_h* vfs, const char* pattern, vfs_error* error);

#endif // VFS_FTP_H
