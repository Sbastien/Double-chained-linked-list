#include "linkedlist.h"
#include <stdlib.h>

void *list_get_at(t_list *list, int index) {
  int idx;
  t_node *tmp;

  if (list && index >= 0 && index < list->size) {
    if (index == 0)
      return (list_get_front(list));
    else if (index == (list->size - 1))
      return (list_get_back(list));
    else {
      idx = 0;
      tmp = list->head;
      while (idx < list->size) {
        if (idx == index)
          return (tmp->data);
        tmp = tmp->next;
        idx++;
      }
    }
  }
  return (NULL);
}
