#include "linkedlist.h"
#include <stdlib.h>

void list_pop_back(t_list *list) {
  t_node *tmp;

  tmp = NULL;
  if (list && list->size > 0) {
    if (list->size == 1) {
      tmp = list->tail;
      list->head = NULL;
      list->tail = NULL;
    } else {
      tmp = list->tail;
      list->tail->prev->next = list->tail->next;
      list->tail->next->prev = list->tail->prev;
      list->tail = list->tail->prev;
    }
    if (list->del_data)
      list->del_data(&tmp->data);
    list->size -= 1;
    free(tmp);
  }
}
