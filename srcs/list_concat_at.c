#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

static t_node *get_node_at(t_list *list, int index) {
  t_node *tmp;

  tmp = list->head;
  while (index > 0) {
    tmp = tmp->next;
    index--;
  }
  return (tmp);
}

int list_concat_at(t_list *dest, t_list *src, int index) {
  t_list *new_list;
  t_node *current;
  t_node *tmp;

  if (dest && src && src->dup_data && index >= 0) {
    if (index == 0)
      list_concat_front(dest, src);
    else if (index >= dest->size)
      list_concat_back(dest, src);
    else if ((new_list = list_dup(src))) {
      current = get_node_at(dest, index - 1);
      tmp = current->next;
      current->next = new_list->head;
      new_list->head->prev = current;
      new_list->tail->next = tmp;
      tmp->prev = new_list->tail;
      dest->size += new_list->size;
      free(new_list);
      return (0);
    }
  }
  return (1);
}
