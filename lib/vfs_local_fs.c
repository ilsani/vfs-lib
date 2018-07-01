#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <vfs.h>
#include <vfs_local_fs.h>
#include <vfs_file.h>

extern int vfs_local_fs_open(const vfs_h* vfs) {

  return 0;
}

extern int vfs_local_fs_close(const vfs_h* vfs) {

  return 0;
}

extern vfs_file_search_result* vfs_local_fs_get_files(const vfs_h* vfs,
						      const char* pattern,
						      vfs_error* error) {
  *error = E_NO_ERR;

  if (!vfs->config->uri || strlen(vfs->config->uri) <= 0) {
    *error = E_INVALID_URI;
    return NULL;
  }

  DIR* dir;

  if ((dir = opendir(vfs->config->uri)) != NULL) {
    
    struct dirent* ent;
    vfs_file_search_result* result = vfs_file_search_result_alloc();
    
    while ((ent = readdir(dir)) != NULL) {
      
      char path[strlen(ent->d_name) + strlen(vfs->config->uri) + 1];
      snprintf(path, sizeof(path), "%s/%s", vfs->config->uri, ent->d_name);

      struct stat ent_stat;
      stat(path, &ent_stat);

      if (!S_ISREG(ent_stat.st_mode)) {
	continue;
      }

      vfs_file* file = vfs_file_alloc(ent->d_name);

      // ent->d_name
      // ent->d_reclen
      // ent_stat.st_size
      // ent_stat.st_uid
      // ent_stat.st_gid

      vfs_file_search_result_add_item(result, file);
    }

    closedir(dir);
    return result;
  }
  else {
    *error = E_INVALID_URI;
    return NULL;
  }
  
  return NULL;
}
