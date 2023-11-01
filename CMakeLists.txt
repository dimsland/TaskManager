set(CMAKE_MINIMUM_REQUIRED 3.23)
project(TaskManager)

set(CMAKE_C_STANDARD 11)

add_executable(
    ${PROJECT_NAME}
    main.c
    task_manager_interface.c
)
