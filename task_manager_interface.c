#include "task_manager_interface.h"
#include <stdio.h>

void menu(Task tasks[], int taskCount)
{
    printf("-----[Menu]------\n");
    printf("1. Add task\n");
    printf("2. Delete task\n");
    printf("3. Change status of task\n");
    printf("4. Change status of tasks\n");
    printf("5. Print all tasks\n");
    printf("6. Print task and status\n");
    printf("0. Exit\n");
    printf("Number: ");
}

void printTasks(Task tasks[], int taskCount)
{
    printf("Task manager:\n");
    printf("---------------------------------------------------------\n");
    printf("   Task |     Deadline | priority | Status \n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < taskCount; i++)
    {
        printf("%8s     %d.%d.%d      %d ", tasks[i].description, tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year, tasks[i].priority);
        if (tasks[i].status == NEW)
        {
            printf("NEW\n");
        }
        else if (tasks[i].status == IN_PROGRESS)
        {
            printf("IN_PROGRESS\n");
        }
        else if (tasks[i].status == TESTING)
        {
            printf("TESTING\n");
        }
        else if (tasks[i].status == DONE)
        {
            printf("DONE\n");
        }
        else
        {
            printf("NEW\n");
        }
    }

    printf("---------------------------------------------------------\n");
}
void printTaskStatus(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int todoCount = 0;
        int doneCount = 0;
        for (int i = 0; i < taskCount; i++)
        {
            if (tasks[i].status == 0)
            {
                todoCount++;
            }
            else
            {
                doneCount++;
            }
        }
        printf("Tasks:\n");
        printf("In progress: %d\n", todoCount);
        printf("Done: %d\n", doneCount);
    }
    else
    {
        printf("No tasks to display.\n");
    }
}

void scanTasks(Task tasks[], int taskCount)
{
    Task newTask;
    printf("Description: ");
    scanf(" %s", newTask.description);
    printf("Priority (1-5): ");
    scanf("%d", &newTask.priority);
    newTask.status = 0;
    printf("Status (NEW, IN_PROGRESS, TESTING, DONE): ");
    char state[20];
    scanf(" %s", state);
    if (!strcmp(state, "New"))
    {
        newTask.status = NEW;
    }
    else if (!strcmp(state, "IN_PROGRESS"))
    {
        newTask.status = IN_PROGRESS;
    }
    else if (!strcmp(state, "TESTING"))
    {
        newTask.status = TESTING;
    }
    else if (!strcmp(state, "DONE"))
    {
        newTask.status = DONE;
    }
    else
    {
        newTask.status = NEW;
    }
    printf("Deadline: ");
    scanf(" %d.%d.%d", &newTask.deadline.day, &newTask.deadline.month, &newTask.deadline.year);
    tasks[taskCount - 1] = newTask;
    printf("Task added.\n");
}

int deleteTasks(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int deleteIndex;
        printTasks(tasks, taskCount);
        printf("Enter the index");
        if (taskCount > 0)
        {
            int changeIndex;
            printTasks(tasks, taskCount);
            printf("Enter the index of the task to change status: ");
            scanf("%d", &changeIndex);

            if (changeIndex >= 0 && changeIndex < taskCount)
            {
                tasks[changeIndex].status = (tasks[changeIndex].status == 0) ? 1 : 0;
                printf("Task at index %d status changed.\n", changeIndex);
            }
            else
            {
                printf("Invalid index.\n");
            }
        }
        else
        {
            printf("No tasks to change status.\n");
        }

        scanf("%d", &deleteIndex);

        if (deleteIndex >= 0 && deleteIndex < taskCount)
        {
            for (int i = deleteIndex; i < taskCount - 1; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            printf("Task at index %d deleted.\n", deleteIndex);
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
};

void changeTasks(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int changeIndex;
        printTasks(tasks, taskCount);
        printf("Enter the index of the task to change status: ");
        scanf("%d", &changeIndex);

        if (changeIndex >= 0 && changeIndex < taskCount)
        {
            tasks[changeIndex].status = (tasks[changeIndex].status == 0) ? 1 : 0;
            printf("Task at index %d status changed.\n", changeIndex);
        }
        else
        {
            printf("Invalid index.\n");
        }
    }
    else
    {
        printf("No tasks to change status.\n");
    }
};

void changeTask(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        for (int i = 0; i < taskCount; i++)
        {
            tasks[i].status = 1;
        }
        printf("All tasks set to 'DONE'.\n");
    }
    else
    {
        printf("No tasks to change status.\n");
    }
};
