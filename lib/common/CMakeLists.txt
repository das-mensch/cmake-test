cmake_minimum_required(VERSION 3.11)

add_subdirectory("list")

add_library(libdasmenschcommon list/list.c)
