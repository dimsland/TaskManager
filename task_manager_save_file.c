#include <stdio.h>
#include "task_manager_save_file.h"
#include "task_manager_interface.h"
#include "task_manager_interface_ge.h"
#include "structuries.h"
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INITIAL_TASK_CAPACITY 10

void changeLanguage(int selectLanguage, FunctionPointers *fp) {
    switch (selectLanguage) {
        case 1:
            printf("\033[0;35m English language selected. \033[0m\n");

            fp->menu = menu;
            fp->printTasks = printTasks;
            fp->scanTasks = scanTasks;
            fp->deleteTasks = deleteTasks;
            fp->changeTasks = changeTasks;
            fp->changeTask = changeTask;
            fp->printTaskStatus = printTaskStatus;
            break;
        case 2:
            setlocale(LC_ALL, "de_DE.UTF-8");
            printf(" \033[0;36m Deutsche Sprache ausgewählt.\033[0m\n");
            fp->menu = menu_ge;
            fp->printTasks = printTasks_ge;
            fp->scanTasks = scanTasks_ge;
            fp->deleteTasks = deleteTasks_ge;
            fp->changeTasks = changeTasks_ge;
            fp->changeTask = changeTask_ge;
            fp->printTaskStatus = printTaskStatus_ge;
            break;
        default:
            printf("\033[0;35m Invalid choice. Defaulting to English.\033[0m\n");
            fp->menu = menu;
            fp->printTasks = printTasks;
            fp->scanTasks = scanTasks;
            fp->deleteTasks = deleteTasks;
            fp->changeTasks = changeTasks;
            fp->changeTask = changeTask;
            fp->printTaskStatus = printTaskStatus;
            break;
    }
}

void saveTasks(Task tasks[], int taskCount, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        if (fprintf(file, "%s %d %d %d %d\n", tasks[i].description, tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year, tasks[i].priority) < 0) {
            printf("Error writing to file\n");
            fclose(file);
            return;
        }
        if (fprintf(file, "%d\n", tasks[i].status) < 0) {
            printf("Error writing to file\n");
            fclose(file);
            return;
        }
    }

    fclose(file);
}

int loadTasks(Task **tasksRef, int *currentCapacityRef, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Task file not found. A new task list will be created.\n");
        *tasksRef = NULL;
        return 0;
    }

    int taskCount = 0;

    *currentCapacityRef = INITIAL_TASK_CAPACITY;
    *tasksRef = malloc(sizeof(Task) * (*currentCapacityRef));

    if (*tasksRef == NULL) {
        fclose(file);
        return -1; // Возвращает -1 если не удалось выделить память
    }

    while (fscanf(file, "%s %d %d %d %d", (*tasksRef)[taskCount].description, &(*tasksRef)[taskCount].deadline.day,
                  &(*tasksRef)[taskCount].deadline.month, &(*tasksRef)[taskCount].deadline.year,
                  &(*tasksRef)[taskCount].priority) == 5) {
        int status;
        if (fscanf(file, "%d", &status) == 1) {
            (*tasksRef)[taskCount].status = status;
        } else {
            (*tasksRef)[taskCount].status = NEW;
        }
        taskCount++;

        if (taskCount >= *currentCapacityRef) {
            *currentCapacityRef *= 2;
            Task *newTasks = realloc(*tasksRef, sizeof(Task) * (*currentCapacityRef));
            if (!newTasks) {
                fclose(file);
                return -1; // Возвращает -1 если не удалось изменить размер памяти
            }
            *tasksRef = newTasks;
        }
    }

    fclose(file);
    return taskCount;
}

