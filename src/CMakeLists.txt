cmake_minimum_required(VERSION 3.25)
project(TaskManager)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib)

add_subdirectory(file_manager)

add_subdirectory(interface)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PUBLIC tm_interface)

target_link_libraries(${PROJECT_NAME} PUBLIC tm_file_manager)

file(COPY languages DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

file(COPY saves DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
