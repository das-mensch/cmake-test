#include "list.h"
#include <stdlib.h>

List * createList() {
  return (List *)malloc(sizeof(List));
}

void pushListEntry(List * list, void * data) {
  ListEntry * newEntry = (ListEntry *)malloc(sizeof(ListEntry));
  newEntry->data = data;
  newEntry->next = NULL;
  newEntry->prev = NULL;
  if (list->head == NULL) {
    list->head = list->tail = newEntry;
    return;
  }
  ListEntry * formerTail = list->tail;
  formerTail->next = newEntry;
  newEntry->prev = formerTail;
  list->tail = newEntry;
}

void deleteListEntry(List * list, ListEntry * toDelete) {
  ListEntry * current = list->head;
  while (current != NULL) {
    if (current != toDelete) {
      current = current->next;
      continue;
    }
    ListEntry * previous = current->prev;
    ListEntry * next = current->next;
    if (previous == NULL) {
      list->head = next;
    } else {
      previous->next = next;
    }
    if (next == NULL) {
      list->tail = previous;
    } else {
      next->prev = previous;
    }
    return;
  }
}

void walkList(List * list, void walkFn(ListEntry *), WalkDirection_t direction) {
  ListEntry * current = (direction == FORWARD) ? list->head : list->tail;
  while (current != NULL) {
    walkFn(current);
    current = (direction == FORWARD) ? current->next : current->prev;
  }
}
