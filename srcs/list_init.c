#include "linkedlist.h"
#include <stdlib.h>

t_list *list_init(void (*del_data)(void **), void *(*dup_data)(void *)) {
  t_list *new_list;

  if ((new_list = malloc(sizeof(*new_list))) != NULL) {
    new_list->size = 0;
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->del_data = del_data;
    new_list->dup_data = dup_data;
  }
  return (new_list);
}
