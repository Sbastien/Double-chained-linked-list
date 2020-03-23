#include "linkedlist.h"

int list_push_front(t_list *list, void *data) {
  if (list_push_back(list, data)) {
    list->head = list->tail;
    list->tail = list->tail->prev;
    return (1);
  }
  return (0);
}
