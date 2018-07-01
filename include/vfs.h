#ifndef VFS_H
#define VFS_H

#define MAX_PATH (2048)

enum _vfs_error {
  E_NO_ERR,
  E_MEM,
  E_INVALID_CONFIG,
  E_INVALID_PROTOCOL,
  E_INVALID_URI
};

typedef enum _vfs_error vfs_error;

typedef struct _vfs_config {

  // char connection_string[MAX_PATH];

  char proto[MAX_PATH];
  char uri[MAX_PATH];
  char username[MAX_PATH];
  char password[MAX_PATH];
  
} vfs_config;

typedef struct _vfs_file {

  char name[MAX_PATH];
  char store_path[MAX_PATH];
  int size;
  int level;
  
} vfs_file;

typedef struct _vfs_file_list {

  vfs_file* file;
  struct _vfs_file_list* next;
  
} vfs_file_list;

typedef struct _vfs_file_search_result {

  int n_items;
  vfs_file_list* files;

} vfs_file_search_result;

typedef struct _vfs_h {

  vfs_config* config;

  int (*open)(const struct _vfs_h* vfs);
  int (*close)(const struct _vfs_h* vfs);
  vfs_file_search_result* (*get_files)(const struct _vfs_h* vfs, const char* pattern);
  
} vfs_h;

extern vfs_h* vfs_new(const vfs_config* config, vfs_error* error);
extern void vfs_close(vfs_h* vfs);
extern void vfs_file_search_result_free(vfs_file_search_result* result);

#endif // VFS_H
