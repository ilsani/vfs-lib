#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vfs.h>
#include <vfs_local_fs.h>

/* static void error_vfs_connection_string_is_invalid() { */
/*   fprintf(stderr, "Invalid connection string.\n"); */
/* } */

/* static char* vfs_connection_string_get_uri(const char* connection_string, */
/* 					   const char* pattern) { */
  
/*   if (!connection_string || !pattern) { */
/*     return NULL; */
/*   } */
  
/*   char* ptr = strstr(connection_string, pattern) + strlen(pattern); */

/*   if (!ptr || ptr[0] == '\0') { */
/*     return NULL; */
/*   } */

/*   size_t uri_len = strlen(ptr) + 1; */
/*   char* uri = malloc(uri_len * sizeof(char)); */
  
/*   if (!uri) { */
/*     fprintf(stderr, "Unable to get uri from connection string due to a " */
/* 	    "malloc() error.\n"); */
/*     return NULL; */
/*   } */

/*   snprintf(uri, uri_len, ptr); */

/*   /\* int i = 0; *\/ */
/*   /\* char* p = uri; *\/ */
/*   /\* while (1) { *\/ */
/*   /\*   printf("[%d] => %c\n", i, *p++); *\/ */
/*   /\*   i = i + 1; *\/ */
/*   /\*   if (!*p) { *\/ */
/*   /\*     printf("[%d] => EOF\n\n", i); *\/ */
/*   /\*     break; *\/ */
/*   /\*   } *\/ */
/*   /\* } *\/ */
    
/*   return uri; */
/* } */

static int vfs_init(vfs_h* vfs, const vfs_config* config) {

  if (!config || !config->proto || !config->uri) {
    return -1;
  }

  if (!strcmp(config->proto, "local")) {
    
    vfs->open = vfs_local_fs_open;
    vfs->close = vfs_local_fs_close;
    vfs->get_files = vfs_local_fs_get_files;

  }
  else if (!strcmp(config->proto, "ftp")) {

    // TODO: methods and settings

    if (!config->username) {
      snprintf(vfs->config->username, sizeof(vfs->config->username), "anonymous");
    }
    if (!config->password) {
      snprintf(vfs->config->password, sizeof(vfs->config->password), "anonymous");
    }
    
    return -1;
    
  }
  else {
    fprintf(stderr, "Invalid protocol.\n");
    return -1;
  }

  return 0;

}

// //////////////////////////////////////////////////////////////////////////

extern vfs_h* vfs_new(const vfs_config* config) {

  vfs_h* vfs = malloc(sizeof(vfs_h));
  vfs->config = (vfs_config *) config;

  if (vfs == NULL) {
    fprintf(stderr, "Unable to create new VFS handler due to a malloc() "
	    "error.\n");
    return NULL;
  }

  if (vfs_init(vfs, config) < 0) {
    fprintf(stderr, "Unable to create new VFS handler due to a "
	    "configuration error.\n");
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


