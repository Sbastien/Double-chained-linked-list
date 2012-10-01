// Copyright 2012 Sebastien Loyer

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include	<stdlib.h>
#include	"linkedlist.h"

t_list		*list_init(void (*del_data)(void**),
			   void *(*dup_data)(void*))
{
  t_list        *new_list;

  if ((new_list = malloc(sizeof(*new_list))) != NULL)
    {
      new_list->size = 0;
      new_list->head = NULL;
      new_list->tail = NULL;
      new_list->del_data = del_data;
      new_list->dup_data = dup_data;
    }
  return (new_list);
}
