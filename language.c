#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "language.h"
#include <strings.h>


Language select_language(const char *path)
{
    Language lang;

    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Unable to open language file.\n");
        exit(1);
    }

    for (int i = 0; i < MENU_HEIGHT; i++)
    {
        fgets(lang.menu[i], sizeof(lang.menu[i]), file);
        lang.menu[i][strcspn(lang.menu[i], "\n")] = '\0';
    }

    for (int i = 0; i < PRINT_TASK_HEIGHT; i++)
    {
        fgets(lang.printTask[i], sizeof(lang.printTask[i]), file);
        lang.printTask[i][strcspn(lang.printTask[i], "\n")] = '\0';
    }

    for (int i = 0; i < SCAN_TASKS_HEIGHT; i++)
    {
        fgets(lang.scanTasks[i], sizeof(lang.scanTasks[i]), file);
        lang.scanTasks[i][strcspn(lang.scanTasks[i], "\n")] = '\0';
    }

    for (int i = 0; i < DELETE_TASKS_HEIGHT; i++)
    {
        fgets(lang.deleteTasks[i], sizeof(lang.deleteTasks[i]), file);
        lang.deleteTasks[i][strcspn(lang.deleteTasks[i], "\n")] = '\0';
    }

    for (int i = 0; i < CHANGE_TASKS_HEIGHT; i++)
    {
        fgets(lang.changeTasks[i], sizeof(lang.changeTasks[i]), file);
        lang.changeTasks[i][strcspn(lang.changeTasks[i], "\n")] = '\0';
    }

    for (int i = 0; i < CHANGE_TASK_HEIGHT; i++)
    {
        fgets(lang.changeTask[i], sizeof(lang.changeTask[i]), file);
        lang.changeTask[i][strcspn(lang.changeTask[i], "\n")] = '\0';
    }

    for (int i = 0; i < PRINT_TASK_STATUS_HEIGHT; i++)
    {
        fgets(lang.printTaskStatus[i], sizeof(lang.printTaskStatus[i]), file);
        lang.printTaskStatus[i][strcspn(lang.printTaskStatus[i], "\n")] = '\0';
    }

    fclose(file);
    return lang;
}
