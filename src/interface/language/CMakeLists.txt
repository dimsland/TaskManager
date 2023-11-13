cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/lang_lib)

add_library(tm_language SHARED language.c)

set_target_properties(tm_language PROPERTIES LINKER_LANGUAGE C)