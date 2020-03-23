#include "linkedlist.h"
#include <stdlib.h>

void list_clear(t_list *list) {
  if (list) {
    while (list->size > 0)
      list_pop_back(list);
  }
}
