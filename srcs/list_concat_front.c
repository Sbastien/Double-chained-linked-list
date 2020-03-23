#include "linkedlist.h"

int list_concat_front(t_list *dest, t_list *src) {
  int i;
  t_node *tmp;

  if (dest && src && src->dup_data) {
    i = 0;
    tmp = src->tail;
    while (i < src->size) {
      if (!list_push_front(dest, src->dup_data(tmp->data)))
        return (0);
      tmp = tmp->prev;
      i++;
    }
  }
  return (1);
}
