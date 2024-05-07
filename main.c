#include <stdio.h>
#include "common/list.h"

void walker(ListEntry * e) {
  printf("Entry: %d\n", *(int*)e->data);
}

int main (int argc, char ** argv) {
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  List * list = createList();
  pushListEntry(list, &a);
  pushListEntry(list, &b);
  pushListEntry(list, &c);
  pushListEntry(list, &d);
  printf("Forward:\n");
  walkList(list, walker, FORWARD);
  printf("Backward:\n");
  walkList(list, walker, BACKWARD);
  deleteListEntry(list, list->head->next->next);
  printf("Forward:\n");
  walkList(list, walker, FORWARD);
}
