#include <stdio.h>
#include <stdlib.h>

#include <vfs.h>
#include <vfs_file.h>

int main() {

  vfs_config* conf = malloc(sizeof(vfs_config));
  snprintf(conf->proto, sizeof(conf->proto), "%s", "local");
  snprintf(conf->uri, sizeof(conf->uri), "%s", "/dev/shm");
      
  vfs_error err;
  vfs_h* vfs = vfs_new(conf, &err);
  vfs->open(vfs);

  vfs_file_search_result* result = vfs->get_files(vfs, NULL, &err);

  printf("n_elem => %ld\n", result->n_items);
  
  vfs_file_list* node = result->files;
  int i = 0;
  
  while (node) {
    printf("%d: %s\n", i, node->file->name);
    i++;
    node = node->next;
  }

  vfs_file_search_result_free(&result);

  vfs_close(&vfs);
  
  return 0;
  
}
