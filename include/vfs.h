#ifndef VFS_H
#define VFS_H

#include <vfs_config.h>
#include <vfs_file.h>

typedef enum _vfs_error {
  
  E_NO_ERR,
  E_MEM,
  E_INVALID_CONFIG,
  E_INVALID_PROTOCOL,
  E_INVALID_URI
  
} vfs_error;

typedef struct _vfs_config {

  // char connection_string[MAX_PATH];

  char proto[MAX_PATH];
  char uri[MAX_PATH];
  char username[MAX_PATH];
  char password[MAX_PATH];
  
} vfs_config;

typedef struct _vfs_h {

  vfs_config* config;

  int (*open)(const struct _vfs_h* vfs);
  int (*close)(const struct _vfs_h* vfs);
  vfs_file_search_result* (*get_files)(const struct _vfs_h* vfs, const char* pattern, vfs_error* error);
  
} vfs_h;

extern vfs_h* vfs_new(const vfs_config* config, vfs_error* error);
extern void vfs_close(vfs_h* vfs);

#endif // VFS_H
