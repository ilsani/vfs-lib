#ifndef VFS_FILE_H
#define VFS_FILE_H

#include <vfs_config.h>

typedef struct _vfs_file {

  char name[MAX_PATH];
  char store_path[MAX_PATH];
  size_t size;
  size_t level;
  
} vfs_file;

typedef struct _vfs_file_list {

  vfs_file* file;
  struct _vfs_file_list* next;
  
} vfs_file_list;

typedef struct _vfs_file_search_result {

  size_t n_items;
  vfs_file_list* files;

} vfs_file_search_result;

extern void vfs_file_search_result_free(vfs_file_search_result* result);
extern vfs_file_search_result* vfs_file_search_result_alloc();
extern void vfs_file_search_result_add_item(vfs_file_search_result* search_result, vfs_file* file);

#endif // VFS_FILE_H