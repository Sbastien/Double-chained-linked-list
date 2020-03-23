#include "linkedlist.h"
#include <stdlib.h>

int list_find(t_list *list, int (*to_compare)(void *, void *), void *to_find) {
  t_node *tmp;
  int index;

  index = 0;
  if (list && to_compare) {
    tmp = list->head;
    while (index < list->size) {
      if (to_compare(tmp->data, to_find))
        return (index);
      tmp = tmp->next;
      index++;
    }
  }
  return (-1);
}
