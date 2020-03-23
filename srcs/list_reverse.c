#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

static void reverse_node(t_node *node) {
  t_node *tmp;

  if (node) {
    tmp = node->next;
    node->next = node->prev;
    node->prev = tmp;
  }
}

void list_reverse(t_list *list) {
  int index;
  t_node *current;
  t_node *tmp;

  index = 0;
  if (list && list->size > 1) {
    current = list->head;
    while (index < list->size) {
      tmp = current->next;
      reverse_node(current);
      current = tmp;
      index++;
    }
    tmp = list->head;
    list->head = list->tail;
    list->tail = tmp;
  }
}
