#include "linkedlist.h"

static void it_rev_real(t_list *list, void (*to_apply)(void **), int limit) {
  int i;
  t_node *tmp;

  if (list && to_apply) {
    tmp = list->tail;
    if (limit == 0 || limit > list->size)
      limit = list->size;
    i = limit;
    while (i > 0) {
      to_apply(&tmp->data);
      tmp = tmp->prev;
      i--;
    }
  }
}

void list_iter_rev(t_list *list, void (*to_apply)(void **)) {
  it_rev_real(list, to_apply, 0);
}

void list_niter_rev(t_list *list, void (*to_apply)(void **), int limit) {
  if (limit <= 0)
    return;
  it_rev_real(list, to_apply, limit);
}
