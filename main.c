#include "task_manager_interface.h"
#include <stdio.h>

int main() {
    struct Task* tasks = NULL;
    int taskCount = 0;
    int choice;


    while (1) {
    menu(tasks, taskCount);
    fflush(stdin);
    scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("CALLED CASE 1");
                ++taskCount;
                if (tasks == NULL ){
                    tasks = (Task*)malloc(taskCount * sizeof(Task));

                }else{
                    tasks = (Task*)realloc(tasks,taskCount * sizeof( Task));
                }
               scanTasks(tasks, taskCount);
                break;

            case 2:
             printf("CALLED CASE 2");
                taskCount = deleteTasks(tasks,taskCount);

                if (taskCount == 0 ){
                    free(tasks);
                    tasks = NULL;
                }else{
                    tasks = (Task*)realloc(tasks, taskCount * sizeof(Task));
                }
                break;
            case 3:
             printf("CALLED CASE 3");
                changeTasks(tasks,taskCount);

                break;
            case 4:
             printf("CALLED CASE 4");
                changeTask(tasks, taskCount);
                break;
                if (taskCount > 0) {
                    printTasks(tasks, taskCount);
                } else {
                    printf("No tasks to display.\n");
                }
                break;
            case 5:
             printf("CALLED CASE 5");
                printTasks(tasks, taskCount);
                break;
            case 6:
             printf("CALLED CASE 6");
                printTaskStatus(tasks,taskCount);
                break;
            case 0:
                printf("Exit.\n");
                if(tasks != NULL){
                free(tasks);}
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
