#include "linkedlist.h"
#include <stdlib.h>

t_list *list_dup(t_list *list) {
  int i;
  t_node *tmp;
  t_list *new_list;

  new_list = NULL;
  if (list && (new_list = list_init(list->del_data, list->dup_data))) {
    i = 0;
    tmp = list->head;
    while (i < list->size) {
      if (!list_push_back(new_list, new_list->dup_data(tmp->data))) {
        list_delete(new_list);
        return (NULL);
      }
      tmp = tmp->next;
      i++;
    }
  }
  return (new_list);
}
