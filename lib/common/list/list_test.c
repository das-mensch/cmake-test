#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

typedef struct testcase {
  char * name;
  void (*function) (void);
} testcase_t;

#define ADD_TEST(NAME) { #NAME, NAME }

void test_empty_list() {
  List * sut = createList();
  assert(("list is not empty after creation", sut->head == NULL && sut->tail == NULL));
}

void test_push_entry() {
  List * sut = createList();
  int value = 1337;
  pushListEntry(sut, &value);
  assert(("could not add list entry", sut->head == sut->tail && *(int*)sut->head->data == value));
}

void test_delete_entry() {
  List * sut = createList();
  int value = 1337;
  pushListEntry(sut, &value);
  deleteListEntry(sut, sut->head);
  assert(("list is not empty after deletion", sut->head == NULL && sut->tail == NULL));
}

void test_delete_middle_entry() {
  List * sut = createList();
  int value1 = 1;
  int value2 = 2;
  int value3 = 3;
  pushListEntry(sut, &value1);
  pushListEntry(sut, &value2);
  pushListEntry(sut, &value3);
  deleteListEntry(sut, sut->head->next);
  assert((
    "list is not empty after deletion",
    *(int*)sut->head->data == value1
      && *(int*)sut->tail->data == value3
      && sut->head->next == sut->tail
  ));
}

void test_delete_head_entry() {
  List * sut = createList();
  int value1 = 1;
  int value2 = 2;
  int value3 = 3;
  pushListEntry(sut, &value1);
  pushListEntry(sut, &value2);
  pushListEntry(sut, &value3);
  deleteListEntry(sut, sut->head);
  assert((
    "list is not empty after deletion",
    *(int*)sut->head->data == value2
      && *(int*)sut->tail->data == value3
      && sut->head->prev == NULL
  ));
}

void test_delete_tail_entry() {
  List * sut = createList();
  int value1 = 1;
  int value2 = 2;
  int value3 = 3;
  pushListEntry(sut, &value1);
  pushListEntry(sut, &value2);
  pushListEntry(sut, &value3);
  deleteListEntry(sut, sut->tail);
  assert((
    "list is not empty after deletion",
    *(int*)sut->head->data == value1
      && *(int*)sut->tail->data == value2
      && sut->tail->next == NULL
  ));
}

int main (int argc, char ** argv) {
  assert(("no test argument given", argc > 1));
  testcase_t testsuite[] = {
    ADD_TEST(test_empty_list),
    ADD_TEST(test_push_entry),
    ADD_TEST(test_delete_entry),
    ADD_TEST(test_delete_middle_entry),
    ADD_TEST(test_delete_head_entry),
    ADD_TEST(test_delete_tail_entry),
  };

  for (int i = 0; i < sizeof(testsuite) / sizeof(testsuite[1]); i++) {
    testcase_t current = testsuite[i];
    printf("current test '%s'\n", current.name);
    if (strcmp(current.name, argv[1]) == 0) {
      current.function();
      exit(0);
    }
  }
  printf("could not find test '%s'\n", argv[1]);
  exit(2);
}
