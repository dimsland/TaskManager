#include <stdio.h>
#include "task_manager_save_file.h"
#include "task_manager_interface.h"
#include "task_manager_interface_ge.h"
#include "structuries.h"
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void changeLanguage(int selectLanguage, FunctionPointers *fp)
{
    switch (selectLanguage)
    {
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

void saveTasks(Task tasks[], int taskCount, const char *filename)
{
    FILE *file = fopen(filename, "wb+");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file for writing\n");
        return;
    }

   fwrite(tasks,sizeof(Task),taskCount, file);

    fclose(file);
}

Task* loadTasks(Task *tasks, int *taskCount, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Task file not found. A new task list will be created.\n");
        *taskCount = 0 ;
        return (Task*) malloc(sizeof(Task) ); ;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftello(file);
    rewind(file); 
    *taskCount = (fileSize / sizeof(Task))+1;
    tasks = (Task*) malloc(sizeof(Task) * (*taskCount));
    
    size_t tasksRead = fread(tasks, sizeof(Task), *taskCount, file);
    if (tasksRead != *taskCount) {
        
        perror("Error reading tasks from file.\n");
        fclose(file);
        return tasks;
    }
    fclose(file);
    return tasks; 
}
