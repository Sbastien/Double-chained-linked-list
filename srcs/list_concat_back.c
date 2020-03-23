#include "linkedlist.h"
#include <stdio.h>

int list_concat_back(t_list *dest, t_list *src) {
  int i;
  t_node *tmp;

  i = 0;
  if (dest && src && src->dup_data) {
    tmp = src->head;
    while (i < src->size) {
      if (!list_push_back(dest, src->dup_data(tmp->data)))
        return (0);
      tmp = tmp->next;
      i++;
    }
  }
  return (1);
}
