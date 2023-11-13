#ifndef LANGUAGE_H
#define LANGUAGE_H

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

#define MENU_HEIGHT 8
#define PRINT_TASK_HEIGHT 10
#define SCAN_TASKS_HEIGHT 5
#define DELETE_TASKS_HEIGHT 2
#define CHANGE_TASKS_HEIGHT 3
#define CHANGE_TASK_HEIGHT 2
#define PRINT_TASK_STATUS_HEIGHT 4

typedef struct
{
    char menu[MENU_HEIGHT][80];
    char scanTasks[SCAN_TASKS_HEIGHT][80];
    char deleteTasks[DELETE_TASKS_HEIGHT][80];
    char changeTask[CHANGE_TASK_HEIGHT][80];
    char changeTasks[CHANGE_TASKS_HEIGHT][80];
    char printTask[PRINT_TASK_HEIGHT][80];
    char printTaskStatus[PRINT_TASK_STATUS_HEIGHT][80];

} Language;

Language select_language(const char *path);

typedef struct
{
    char menu[MENU_HEIGHT][10];
} MenuColors;

MenuColors getMenuColors();

#endif // LANGUAGE_H
