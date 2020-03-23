#include "linkedlist.h"
#include <stdlib.h>

static void add_to_empty_list(t_list *list, t_node **new_node) {
  (*new_node)->next = (*new_node);
  (*new_node)->prev = (*new_node);
  list->head = (*new_node);
  list->tail = (*new_node);
}

static void add_to_list(t_list *list, t_node **new_node) {
  list->tail->next = (*new_node);
  list->head->prev = (*new_node);
  (*new_node)->prev = list->tail;
  (*new_node)->next = list->head;
  list->tail = (*new_node);
}

int list_push_back(t_list *list, void *data) {
  t_node *new_node;

  if (list && data && (new_node = malloc(sizeof(*new_node)))) {
    new_node->data = data;
    if (list->size == 0)
      add_to_empty_list(list, &new_node);
    else
      add_to_list(list, &new_node);
    list->size += 1;
    return (1);
  }
  return (0);
}
