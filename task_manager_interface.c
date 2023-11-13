#include "task_manager_interface.h"
#include <stdio.h>
#include <string.h>
#include "language.h"

void menu(Language lang, MenuColors colors, Task tasks[], int taskCount)
{
    for (int i = 0; i < MENU_HEIGHT; i++)
    {
        if (colors.menu[i] != NULL && lang.menu[i] != NULL)
        {
            printf("%s%s" RESET "\n", colors.menu[i], lang.menu[i]);
        }
        else
        {
            printf("Menu item or color not defined at index %d\n", i);
        }
    }
}

void printTasks(Language lang, Task tasks[], int taskCount)
{

    printf("%s\n", lang.printTask[0]); // "Task manager:\n"
    printf("%s\n", lang.printTask[1]); // "---------------------------------------------------------"
    printf("%s\n", lang.printTask[2]); // "   Task            | Deadline    | Priority   | Status"
    printf("%s\n", lang.printTask[3]);
    for (int i = 0; i < taskCount; i++)
    {

        printf("%-20s %02d.%02d.%04d     %-10d ", tasks[i].description, tasks[i].deadline.day, tasks[i].deadline.month,
               tasks[i].deadline.year, tasks[i].priority);

        const char *statusStr = "";
        switch (tasks[i].status)
        {
        case NEW:
            statusStr = lang.printTask[4];
            break;
        case IN_PROGRESS:
            statusStr = lang.printTask[5];
            break;
        case TESTING:
            statusStr = lang.printTask[6];
            break;
        case DONE:
            statusStr = lang.printTask[7];
            break;
        default:
            statusStr = lang.printTask[8];
            break;
        }
        printf("%-10s\n", statusStr);
    }

    printf("%s\n", lang.printTask[9]);
}

void printTaskStatus(Language lang, Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int todoCount = 0;
        int doneCount = 0;
        for (int i = 0; i < taskCount; i++)
        {
            if (tasks[i].status < DONE)
            {
                todoCount++;
            }
            else
            {
                doneCount++;
            }
        }
        printf("%s\n", lang.printTaskStatus[0]);
        printf(lang.printTaskStatus[1], todoCount);
        printf("\n");
        printf(lang.printTaskStatus[2], doneCount);
        printf("\n");
    }
    else
    {
        printf("%s\n", lang.printTaskStatus[3]);
    }
}

void scanTasks(Language lang, Task tasks[], int taskCount)
{
    Task newTask;
    printf("%s\n", lang.scanTasks[0]);
    scanf(" %[^\n]", newTask.description);
    printf("%s\n", lang.scanTasks[1]);
    scanf("%d", &newTask.priority);
    newTask.status = 0;
    printf("%s\n", lang.scanTasks[2]);
    char state[20];
    scanf(" %s", state);
    if (!strcmp(state, lang.printTask[4]))
    {
        newTask.status = NEW;
    }
    else if (!strcmp(state, lang.printTask[5]))
    {
        newTask.status = IN_PROGRESS;
    }
    else if (!strcmp(state, lang.printTask[6]))
    {
        newTask.status = TESTING;
    }
    else if (!strcmp(state, lang.printTask[7]))
    {
        newTask.status = DONE;
    }
    else
    {
        newTask.status = NEW;
    }
    printf("%s\n", lang.scanTasks[3]);
    scanf(" %d.%d.%d", &newTask.deadline.day, &newTask.deadline.month, &newTask.deadline.year);
    tasks[taskCount - 1] = newTask;
    printf("%s\n", lang.scanTasks[4]);
}

int deleteTasks(Language lang, Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int deleteIndex;
        printTasks(lang, tasks, taskCount);
        printf("%s\n", lang.deleteTasks[0]); // "Enter the index of the task to delete:"
        scanf("%d", &deleteIndex);

        if (deleteIndex >= 0 && deleteIndex < taskCount)
        {
            for (int i = deleteIndex; i < taskCount - 1; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            printf("Task at index %d deleted.\n", deleteIndex); // Используйте printf с форматным спецификатором
        }
        else
        {
            printf("Invalid index.\n");
        }
    }
    else
    {
        printf("No tasks to delete.\n");
    }
    return taskCount;
}

void changeTasks(Language lang, Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int changeIndex;
        printTasks(lang, tasks, taskCount);
        printf("%s\n", lang.changeTasks[0]);
        scanf("%d", &changeIndex);

        if (changeIndex >= 0 && changeIndex < taskCount)
        {
            tasks[changeIndex].status = (tasks[changeIndex].status == 0) ? 1 : 0;
            printf(lang.changeTasks[1], changeIndex);
        }
        else
        {
            printf("%s\n", lang.changeTasks[2]);
        }
    }
    else
    {
        printf("No tasks to change status.\n");
    }
};

void changeTask(Language lang, Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        for (int i = 0; i < taskCount; i++)
        {
            tasks[i].status = DONE;
        }
        printf("%s\n", lang.changeTask[0]);
    }
    else
    {
        printf("%s\n", lang.changeTask[1]);
    }
};