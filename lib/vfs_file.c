#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vfs.h>
#include <vfs_file.h>

extern bool is_valid_filename(const char* filename, const char* pattern) {
  if (!pattern) return true;
  return false;
}

extern vfs_file* vfs_file_alloc(const char* name) {

  vfs_file* file = malloc(sizeof(vfs_file));
  snprintf(file->name, sizeof(file->name), "%s", name);
  return file;
}

extern vfs_file_search_result* vfs_file_search_result_alloc() {
  
  vfs_file_search_result* r = malloc(sizeof(vfs_file_search_result));
  
  if (!r) {
    // TODO: trace error
    return NULL;
  }
  
  r->n_items = 0;
  r->files = NULL;
  return r;
}

extern void vfs_file_search_result_add_item(vfs_file_search_result* search_result,
					    vfs_file* file) {
  if (!search_result) {
    search_result = vfs_file_search_result_alloc();
    if (!search_result) {
      // TODO: trace error
      return;
    }
  }

  if (!search_result->files) {
    search_result->files = malloc(sizeof(vfs_file_list));
    if (!search_result->files) {
      // TODO: trace error
      return;
    }
    search_result->files->next = NULL;
    search_result->files->file = NULL;
  }

  vfs_file_list* current = search_result->files;
  
  if (!current->next && !current->file) {
    current->file = file;
  }
  else {
    while (current->next) {
      current = current->next;
    }
    vfs_file_list* node = malloc(sizeof(vfs_file_list));
    node->next = NULL;
    node->file = file;
    current->next = node;
  }

  search_result->n_items = search_result->n_items + 1;
}

extern void vfs_file_search_result_free(vfs_file_search_result** result) {

  if (!result || !(*result)) {
    return;
  }

  vfs_file_search_result* vfsr = *result;

  if (vfsr->files) {
    vfs_file_list* head = vfsr->files->next;

    if (vfsr->files->file) {
      free(vfsr->files->file);
      vfsr->files->file = NULL;
    }
    
    free(vfsr->files);
    vfsr->files = NULL;

    while (head) {
      vfs_file_list* tmp = head;
      head = head->next;

      if (tmp->file) {
	free(tmp->file);
	tmp->file = NULL;
      }

      free(tmp);
      tmp = NULL;
    }
  }

  if (result) {
    free(*result);
    *result = NULL;
  }
}
