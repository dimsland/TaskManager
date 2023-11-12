#include "task_manager_interface.h"
#include <stdio.h>
#include <string.h>
#include "language.h"

void menu(Language lang, Task tasks[], int taskCount) {
    for (int i = 0; i < MENU_HEIGHT; i++) {
        printf("%s", lang.menu[i]);
        
    }
}

void printTasks(Language lang, Task tasks[], int taskCount) {

    printf("%s", lang.printTask[0]); // "Task manager:\n"
    printf("%s", lang.printTask[1]); // "---------------------------------------------------------"
    printf("%s", lang.printTask[2]); // "   Task            | Deadline    | Priority   | Status"
    printf("%s", lang.printTask[3]);
    for (int i = 0; i < taskCount; i++) {

        printf("%-20s %02d.%02d.%04d     %-10d ", tasks[i].description, tasks[i].deadline.day, tasks[i].deadline.month,
               tasks[i].deadline.year, tasks[i].priority);

        const char *statusStr = "";
        switch (tasks[i].status) {
            case NEW:
                statusStr = "NEW";
                break;
            case IN_PROGRESS:
                statusStr = "IN_PROGRESS";
                break;
            case TESTING:
                statusStr = "TESTING";
                break;
            case DONE:
                statusStr = "DONE";
                break;
            default:
                statusStr = "UNKNOWN";
                break;
        }
        printf("%-10s", statusStr);
    }

    printf("%s", lang.printTask[4]);
}

void printTaskStatus(Language lang, Task tasks[], int taskCount) {
    if (taskCount > 0) {
        int todoCount = 0;
        int doneCount = 0;
        for (int i = 0; i < taskCount; i++) {
            if (tasks[i].status == 0) {
                todoCount++;
            } else {
                doneCount++;
            }
        }
        printf("%s", lang.printTaskStatus[0]); // "Tasks:"
        printf(lang.printTaskStatus[1], todoCount); // "In progress: %d"
        printf(lang.printTaskStatus[2], doneCount); // "Done: %d"
    } else {
        printf("%s", lang.printTaskStatus[3]);
    }
}

void scanTasks(Language lang, Task tasks[], int taskCount) {
    Task newTask;
    printf("%s", lang.scanTasks[0]);
    scanf(" %[^\n]", newTask.description);
    printf("%s", lang.scanTasks[1]);
    scanf("%d", &newTask.priority);
    newTask.status = 0;
    printf("%s", lang.scanTasks[2]);
    char state[20];
    scanf(" %s", state);
    if (!strcmp(state, "New")) {
        newTask.status = NEW;
    } else if (!strcmp(state, "IN_PROGRESS")) {
        newTask.status = IN_PROGRESS;
    } else if (!strcmp(state, "TESTING")) {
        newTask.status = TESTING;
    } else if (!strcmp(state, "DONE")) {
        newTask.status = DONE;
    } else {
        newTask.status = NEW;
    }
    printf("%s", lang.scanTasks[3]);
    scanf(" %d.%d.%d", &newTask.deadline.day, &newTask.deadline.month, &newTask.deadline.year);
    tasks[taskCount - 1] = newTask;
    printf("%s", lang.scanTasks[4]);
}

int deleteTasks(Language lang, Task tasks[], int taskCount) {
    if (taskCount > 0) {
        int deleteIndex;
        printTasks(lang, tasks, taskCount);
        printf("Enter the index");
        if (taskCount > 0) {
            int changeIndex;
            printTasks(lang, tasks, taskCount);
            printf("%s", lang.deleteTasks[0]);
            scanf("%d", &changeIndex);

            if (changeIndex >= 0 && changeIndex < taskCount) {
                tasks[changeIndex].status = (tasks[changeIndex].status == 0) ? 1 : 0;
                printf("Task at index %d status changed.\n", changeIndex);
            } else {
                printf("Invalid index.\n");
            }
        } else {
            printf("No tasks to change status.\n");
        }

        scanf("%d", &deleteIndex);

        if (deleteIndex >= 0 && deleteIndex < taskCount) {
            for (int i = deleteIndex; i < taskCount - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            printf(lang.deleteTasks[1], deleteIndex);
        } else {
            printf("Invalid index.\n");
        }
    } else {
        printf("No tasks to delete.\n");
    }
    return taskCount;
};

void changeTasks(Language lang, Task tasks[], int taskCount) {
    if (taskCount > 0) {
        int changeIndex;
        printTasks(lang, tasks, taskCount);
        printf("%s", lang.changeTasks[0]);
        scanf("%d", &changeIndex);

        if (changeIndex >= 0 && changeIndex < taskCount) {
            tasks[changeIndex].status = (tasks[changeIndex].status == 0) ? 1 : 0;
            printf(lang.changeTasks[1], changeIndex);
        } else {
            printf("%s", lang.changeTasks[2]);
        }
    } else {
        printf("No tasks to change status.\n");
    }
};

void changeTask(Language lang, Task tasks[], int taskCount) {
    if (taskCount > 0) {
        for (int i = 0; i < taskCount; i++) {
            tasks[i].status = 1;
        }
        printf("%s", lang.changeTask[0]);
    } else {
        printf("%s", lang.changeTask[1]);
    }
};