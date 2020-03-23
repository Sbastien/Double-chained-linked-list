#include "linkedlist.h"
#include <stdlib.h>

void list_pop_front(t_list *list) {
  t_node *tmp;

  tmp = NULL;
  if (list && list->size > 0) {
    if (list->size == 1) {
      tmp = list->tail;
      list->head = NULL;
      list->tail = NULL;
    } else {
      tmp = list->head;
      list->head->next->prev = list->head->prev;
      list->head->prev->next = list->head->next;
      list->head = list->head->next;
    }
    list->size -= 1;
    if (list->del_data)
      list->del_data(&tmp->data);
    free(tmp);
  }
}
