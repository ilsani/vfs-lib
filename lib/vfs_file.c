#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vfs.h>
#include <vfs_file.h>

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
  }

  vfs_file* new_file = malloc(sizeof(vfs_file));
  
  snprintf(new_file->name,
	   sizeof(new_file->name),
	   "FILE_1");

  vfs_file_list* current = search_result->files;
  
  if (!current->next && !current->file) {
    current->file = new_file;
  }
  else {
    while (current->next) {
      current = current->next;
    }
    vfs_file_list* node = malloc(sizeof(vfs_file_list));
    node->next = NULL;
    node->file = new_file;
    current->next = node;
  }

  search_result->n_items = search_result->n_items + 1;
}

extern void vfs_file_search_result_free(vfs_file_search_result* result) {

  if (!result) {
    return;
  }

  if (result->files) {
    vfs_file_list* head = result->files;
    
    if (head->file) {
      free(head->file);
      head->file = NULL;
    }

    vfs_file_list* tmp;
    while (head) {
      tmp = head;
      head = head->next;
      if (tmp->file) {
	free(tmp->file);
	tmp->file = NULL;
      }
      free(tmp);
      tmp = NULL;
    }
  }

  free(result);
  result = NULL;
}
