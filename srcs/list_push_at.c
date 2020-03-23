#include "linkedlist.h"
#include <stdlib.h>

static void push_idx(t_list *list, t_node **node, int index) {
  t_node *tmp;
  int i;

  i = 0;
  tmp = list->head;
  while (i < list->size) {
    if (i == (index)) {
      (*node)->next = tmp;
      (*node)->prev = tmp->prev;
      tmp->prev->next = (*node);
      tmp->prev = (*node);
      list->size += 1;
      return;
    }
    tmp = tmp->next;
    i++;
  }
}

int list_push_at(t_list *list, void *data, int index) {
  t_node *new_node;

  if (list && data && index >= 0) {
    if (index == 0)
      return (list_push_front(list, data));
    else if (index >= list->size)
      return (list_push_back(list, data));
    else {
      if ((new_node = malloc(sizeof(*new_node)))) {
        new_node->data = data;
        push_idx(list, &new_node, index);
        return (1);
      }
    }
  }
  return (0);
}
