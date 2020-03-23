#include "linkedlist.h"
#include <stdlib.h>

void *list_get_front(t_list *list) {
  if (list) {
    return (list->head->data);
  }
  return (NULL);
}
