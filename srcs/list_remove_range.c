#include "linkedlist.h"

void list_remove_range(t_list *list, int from, int amount) {
  if (list && from < list->size && from >= 0 && amount > 0) {
    if ((amount + from) > list->size)
      amount = list->size;
    while (amount > 0) {
      list_remove_at(list, from);
      amount--;
    }
  }
}
