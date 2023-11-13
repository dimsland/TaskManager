cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_STANDARD 11)

add_library(tm_file_manager SHARED file_manager.c)

set_target_properties(tm_file_manager PROPERTIES LINKER_LANGUAGE C)