#include "linkedlist.h"
#include <stdio.h>

static t_node *get_node_at(t_list *list, int index) {
  int i;
  t_node *tmp;

  i = 0;
  tmp = list->head;
  while (i < list->size) {
    if (i == index)
      return (tmp);
    i++;
    tmp = tmp->next;
  }
  return (NULL);
}

static void swap_value(t_node *first, t_node *second) {
  void *tmp;

  tmp = first->data;
  first->data = second->data;
  second->data = tmp;
}

void list_swap(t_list *list, int idx_first, int idx_second) {
  if (idx_first < list->size && idx_second < list->size &&
      idx_first != idx_second && idx_second >= 0 && idx_first >= 0) {
    swap_value(get_node_at(list, idx_first), get_node_at(list, idx_second));
  }
}
