#include "task_manager_interface.h"
#include "task_manager_save_file.h"
#include "language.h"
#include "structuries.h"
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int choice;
    int selectLanguage;
    int taskCount = 0;
    
    Task *tasks = NULL;

    taskCount = loadTasks(&tasks, "tasks.txt");
    if (taskCount < 0) {
        fprintf(stderr, "Failed to load tasks or memory allocation failed\n");
        return 1;
    }

    
   changeLanguage(selectLanguage);

    while (1) {
        menu(lang, tasks, taskCount);
        fflush(stdin);

        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("\033[0;31m");
                ++taskCount;
                if (tasks == NULL) {
                    tasks = (Task *)malloc(taskCount * sizeof(Task));
                } else {
                    tasks = (Task *)realloc(tasks, taskCount * sizeof(Task));
                }
                scanTasks(lang, tasks, taskCount);

           printf("\033[0m\n");

                break;
            case 2:
                printf("\033[0;33m");
                taskCount = deleteTasks(lang, tasks, taskCount);
                if (taskCount == 0) {
                    free(tasks);
                    tasks = NULL;
                } else {
                    tasks = (Task *)realloc(tasks, taskCount * sizeof(Task));
                }
                printf("\033[0m\n");
                break;
            case 3:
                printf("\033[0;32m");
                changeTasks(lang,tasks, taskCount);
                printf("\033[0m\n");
                break;
            case 4:
                printf("\033[0;34m");
                changeTask(lang,tasks, taskCount);
                 printf("\033[0m\n");
                break;
            case 5:
            printf("\033[0;35m");
                if (taskCount > 0) {
                    printTasks(lang,tasks, taskCount);
                } else {
                    if (selectLanguage != 2) {
                        printf("No tasks to display.\n");
                    } else {
                        printf("Verruekt.\n");
                    }
                }
                printf("\033[0m\n");
                break;
            case 6:
                printf("\033[0;36m");
                printTaskStatus(lang,tasks, taskCount);
                printf("\033[0m\n");
                break;
            case 0:
                printf("\033[0;31m");
                if (selectLanguage != 2) {
                    printf("Exit.\n");
                } else {
                    printf("Beenden.\n");
                }
                printf("\033[0m\n");
                saveTasks(tasks, taskCount, "tasks.txt");
                if (tasks != NULL) {
                    free(tasks);
                }

                return 0;
            default:
                printf("\033[0;31m");

                if (selectLanguage != 2) {
                    printf("Invalid choice.\n");
                } else {
                    printf("Verruekt.\n");
                }
                printf("\033[0m\n");
        }
    }

    return 0;
}

