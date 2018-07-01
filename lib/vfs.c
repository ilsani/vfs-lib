#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vfs.h>
#include <vfs_local_fs.h>
#include <vfs_ftp.h>

static vfs_error vfs_init(vfs_h* vfs, const vfs_config* config) {

  if (!config) {
    return E_INVALID_CONFIG;
  }

  if (strlen(config->proto) <= 0) {
    return E_INVALID_PROTOCOL;
  }

  if (strlen(config->uri) <= 0) {
    return E_INVALID_URI;
  }

  if (!strcmp(config->proto, "local")) {
    vfs->open = vfs_local_fs_open;
    vfs->close = vfs_local_fs_close;
    vfs->get_files = vfs_local_fs_get_files;
  }
  else if (!strcmp(config->proto, "ftp")) {
    vfs->open = vfs_ftp_open;
    vfs->close = vfs_ftp_close;
    vfs->get_files = vfs_ftp_get_files;

    if (strlen(config->username) <= 0) {
      snprintf(vfs->config->username, sizeof(vfs->config->username), "anonymous");
    }
    if (strlen(config->password) <= 0) {
      snprintf(vfs->config->password, sizeof(vfs->config->password), "anonymous");
    }
  }
  else {
    return E_INVALID_PROTOCOL;
  }

  return E_NO_ERR;

}

// //////////////////////////////////////////////////////////////////////////

extern vfs_h* vfs_new(const vfs_config* config, vfs_error* error) {

  *error = E_NO_ERR;
  vfs_h* vfs = malloc(sizeof(vfs_h));

  if (vfs == NULL) {
    *error = E_MEM;
    return NULL;
  }

  vfs->config = (vfs_config *) config;

  if ((*error = vfs_init(vfs, config)) != E_NO_ERR) {
    return NULL;
  }

  return vfs;
}

extern void vfs_close(vfs_h** vfs) {

  vfs_h* t = *vfs;

  if (t) {
    t->close(t);

    if (t->config) {
      free(t->config);
      t->config = NULL;
    }

    free(*vfs);
    *vfs = NULL;
  }
}


