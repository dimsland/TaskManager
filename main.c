#include "task_manager_interface.h"
#include <stdio.h>

int main() {
    struct Task* tasks = NULL;
    int taskCount = 0;
    int choice;


    while (1) {
        printf("-----[Menu]------\n");
        printf("1. Add task\n");
        printf("2. Delete task\n");
        printf("3. Change status of task\n");
        printf("4. Change status of tasks\n");
        printf("5. Print all tasks\n");
        printf("6. Print task and status\n");
        printf("0. Exit\n");
        printf("Number: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                if (tasks == NULL ){
                    tasks = (struct Task*)malloc(taskCount * sizeof(struct Task));
                }else{
                    tasks = (struct Task*)realloc(tasks, taskCount * sizeof(struct Task));
                }
                scanTasks(tasks, &taskCount);
                break;
            case 2:
                deleteTasks(tasks, &taskCount);
                if (taskCount == 0 ){
                    free(tasks);
                }else{
                    tasks = (struct Task*)realloc(tasks, taskCount * sizeof(struct Task));
                }
                break;
            case 3:
                changeTasks(tasks, &taskCount);

                break;
            case 4:
                changeTask(tasks, &taskCount);
                break;
            case 5:
                if (taskCount > 0) {
                    printTasks(tasks, taskCount);
                } else {
                    printf("No tasks to display.\n");
                }
                break;
            case 6:
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
                    printf("Tasks:\n");
                    printf("In progress: %d\n", todoCount);
                    printf("Done: %d\n", doneCount);
                } else {
                    printf("No tasks to display.\n");
                }
                break;
            case 0:
                printf("Exit.\n");
                if(tasks != 0){
                free(tasks);}
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}



