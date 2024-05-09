#ifndef LIB_DASMENSCH_COMMON_LIST_H
#define LIB_DASMENSCH_COMMON_LIST_H

typedef struct ListEntry {
  struct ListEntry * next;
  struct ListEntry * prev;
  void * data;
} ListEntry;

typedef struct List {
  struct ListEntry * head;
  struct ListEntry * tail;
} List;

typedef enum WalkDirection { FORWARD, BACKWARD } WalkDirection_t;

List * createList();
void pushListEntry(List *, void *);
void deleteListEntry(List *, ListEntry *);
void walkList(List *, void (ListEntry *), WalkDirection_t);

#endif
