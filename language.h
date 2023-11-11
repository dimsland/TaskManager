#ifndef LANGUAGE_H
#define LANGUAGE_H

const int MENU_HEIGHT = 7;
const int PRINT_TASK_HEIGHT = 5;
const int SCAN_TASKS_HEIGHT = 5;
const int DELETE_TASKS_HEIGHT = 2;
const int CHANGE_TASKS_HEIGHT = 3;
const int CHANGE_TASK_HEIGHT = 2;
const int PRINT_TASK_STATUS_HEIGHT = 4;

typedef struct {
    char menu[MENU_HEIGHT][80];
    char scanTasks[SCAN_TASKS_HEIGHT][80];
    char deleteTasks[DELETE_TASKS_HEIGHT][80];
    char changeTask[CHANGE_TASK_HEIGHT][80];
    char changeTasks[CHANGE_TASKS_HEIGHT][80];
    char printTask[PRINT_TASK_HEIGHT][80];
    char printTaskStatus[PRINT_TASK_STATUS_HEIGHT][80];
} Language;

Language select_language(const char *path);

#endif // LANGUAGE_H
