#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "interface/language/language.h"
#include "interface/task_manager_interface.h"
#include "file_manager/file_manager.h"
#include "structuries.h"

int main()
{
    setlocale(LC_ALL, "");
    int choice;
    int selectLanguage;
    int taskCount = 0;

    Task *tasks = NULL;

    tasks = loadTasks(&taskCount, "./saves/tasks.save");

    if (taskCount < 0)
    {
        fprintf(stderr, "Failed to load tasks or memory allocation failed\n");
        return 1;
    }
    MenuColors colors = getMenuColors();

    printf(RED "Select Language: \n" RESET);
    printf(YELLOW "Select Language: 1 for English,\n" RESET);
    printf(GREEN "Select Language: 2 for Deutsch\n" RESET);

    scanf("%d", &selectLanguage);
    Language lang = changeLanguage(selectLanguage);

    while (1)
    {

        menu(lang, colors, tasks, taskCount);

        fflush(stdin);

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("%s", colors.menu[1]);

            ++taskCount;
            if (tasks == NULL)
            {
                tasks = (Task *)malloc(taskCount * sizeof(Task));
            }
            else
            {
                tasks = (Task *)realloc(tasks, taskCount * sizeof(Task));
            }
            scanTasks(lang, tasks, taskCount);
            printf("%s", colors.menu[0]);

            break;
        case 2:
            printf("%s", colors.menu[2]);
            taskCount = deleteTasks(lang, tasks, taskCount);
            if (taskCount == 0)
            {
                free(tasks);
                tasks = NULL;
            }
            else
            {
                tasks = (Task *)realloc(tasks, taskCount * sizeof(Task));
            }
            printf("%s", colors.menu[0]);
            break;
        case 3:
            printf("%s", colors.menu[3]);
            changeTasks(lang, tasks, taskCount);
            printf("%s", colors.menu[0]);
            break;
        case 4:
            printf("%s", colors.menu[4]);
            changeTask(lang, tasks, taskCount);
            printf("%s", colors.menu[0]);
            break;
        case 5:
            printf("%s", colors.menu[5]);
            if (taskCount > 0)
            {
                printTasks(lang, tasks, taskCount);
            }
            else
            {
                if (selectLanguage != 2)
                {
                    printf("No tasks to display.\n");
                }
                else
                {
                    printf("Verruekt.\n");
                }
            }
            printf("%s", colors.menu[0]);
            break;
        case 6:
            printf("%s", colors.menu[6]);
            printTaskStatus(lang, tasks, taskCount);
            printf("%s", colors.menu[0]);
            break;
        case 0:
            printf("%s", colors.menu[7]);
            if (selectLanguage != 2)
            {
                printf("Exit.\n");
            }
            else
            {
                printf("Beenden.\n");
            }
            printf("%s", colors.menu[0]);
            saveTasks(tasks, taskCount, "./saves/tasks.save");
            if (tasks != NULL)
            {
                free(tasks);
            }

            return 0;
        default:
            printf("%s", colors.menu[7]);

            if (selectLanguage != 2)
            {
                printf("Invalid choice.\n");
            }
            else
            {
                printf("Verruekt.\n");
            }
            printf("%s", colors.menu[0]);
        }
    }

    return 0;
}
