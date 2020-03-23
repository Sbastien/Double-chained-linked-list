#include "linkedlist.h"
#include <stdlib.h>

void list_delete(t_list *list) {
  if (list) {
    list_clear(list);
    free(list);
    list = NULL;
  }
}
