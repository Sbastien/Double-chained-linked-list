#include "linkedlist.h"
#include <stdlib.h>

void *list_get_back(t_list *list) {
  if (list) {
    return (list->tail->data);
  }
  return (NULL);
}
