cmake_minimum_required(VERSION 3.11)

add_executable(listtest list.h list.c list_test.c)

enable_testing()

add_test(NAME test_empty_list COMMAND listtest test_empty_list)
add_test(NAME test_push_entry COMMAND listtest test_push_entry)
add_test(NAME test_delete_entry COMMAND listtest test_delete_entry)
add_test(NAME test_delete_middle_entry COMMAND listtest test_delete_middle_entry)
add_test(NAME test_delete_head_entry COMMAND listtest test_delete_head_entry)
add_test(NAME test_delete_tail_entry COMMAND listtest test_delete_tail_entry)
