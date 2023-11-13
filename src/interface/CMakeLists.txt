cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_C_STANDARD 11)

add_subdirectory(language/)

add_library(tm_interface SHARED task_manager_interface.c)

set_target_properties(tm_interface PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(tm_interface PUBLIC tm_language)