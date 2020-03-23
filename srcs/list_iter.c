#include "linkedlist.h"

static void it_real(t_list *list, void (*to_apply)(void **), int limit) {
  int i;
  t_node *tmp;

  if (list && to_apply) {
    i = 0;
    tmp = list->head;
    if (limit == 0 || limit > list->size)
      limit = list->size;
    while (i < list->size && i < limit) {
      to_apply(&tmp->data);
      tmp = tmp->next;
      i++;
    }
  }
}

void list_iter(t_list *list, void (*to_apply)(void **)) {
  it_real(list, to_apply, 0);
}

void list_niter(t_list *list, void (*to_apply)(void **), int limit) {
  if (limit <= 0)
    return;
  it_real(list, to_apply, limit);
}
