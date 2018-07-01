#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vfs.h>
#include <vfs_local_fs.h>

static int vfs_init(vfs_h* vfs, const vfs_config* config, vfs_error* error) {

  if (!config) {
    *error = E_INVALID_CONFIG;
    return -1;
  }

  if (!config->proto || strlen(config->proto) <= 0) {
    *error = E_INVALID_PROTOCOL;
    return -1;
  }

  if (!config->uri || strlen(config->uri) <= 0) {
    *error = E_INVALID_URI;
    return -1;
  }

  if (!strcmp(config->proto, "local")) {
    vfs->open = vfs_local_fs_open;
    vfs->close = vfs_local_fs_close;
    vfs->get_files = vfs_local_fs_get_files;
  }
  else if (!strcmp(config->proto, "ftp")) {

    // TODO: methods

    if (!config->username) {
      snprintf(vfs->config->username, sizeof(vfs->config->username), "anonymous");
    }
    if (!config->password) {
      snprintf(vfs->config->password, sizeof(vfs->config->password), "anonymous");
    }
    
    return -1;
  }
  else {
    *error = E_INVALID_PROTOCOL;
    return -1;
  }

  return 0;

}

// //////////////////////////////////////////////////////////////////////////

extern vfs_h* vfs_new(const vfs_config* config, vfs_error* error) {

  *error = E_NO_ERR;

  vfs_h* vfs = malloc(sizeof(vfs_h));
  vfs->config = (vfs_config *) config;

  if (vfs == NULL) {
    *error = E_MEM;
    return NULL;
  }

  if (vfs_init(vfs, config, error) < 0) {
    return NULL;
  }
  
  return vfs;
}

extern void vfs_close(vfs_h* vfs) {

  if (vfs) {
    vfs->close(vfs);

    if (vfs->config) {
      free(vfs->config);
      vfs->config = NULL;
    }

    free(vfs);
    vfs = NULL;
  }
}

extern void vfs_file_search_result_free(vfs_file_search_result* result) {

  if (!result) {
    return;
  }

  if (result->files) {
    // TODO: free result->files
  }

  free(result);
  result = NULL;
}


