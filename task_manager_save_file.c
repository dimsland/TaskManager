#include <stdio.h>
#include "language.h"
#include "task_manager_save_file.h"
#include "task_manager_interface.h"
#include "structuries.h"
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void changeLanguage(int selectLanguage) {
    FILE *file;
    char buffer[1000];

     Language lang;

    switch(selectLanguage) {
        case 1:
            lang = select_language("/home/dmitrii/Documents/TaskManager/English.lang");
            break;
        case 2:
            lang = select_language("/home/dmitrii/Documents/TaskManager/Deutsch.lang");
            break;
        default:
            printf("\033[0;35m Invalid choice. Defaulting to English.\033[0m\n");
            lang = select_language("/home/dmitrii/Documents/TaskManager/English.lang");
    }
    while (fgets(buffer, 1000, file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

Task* loadTasks(int *taskCount, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Task file not found. A new task list will be created.\n");
        *taskCount = 0;
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftello(file);
    rewind(file);

    *taskCount = fileSize / sizeof(Task);
    Task *tasks = (Task*) malloc(sizeof(Task) * (*taskCount));
    if (tasks == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        *taskCount = -1; 
        return NULL;
    }
    
    size_t tasksRead = fread(tasks, sizeof(Task), *taskCount, file);
    if (tasksRead != *taskCount) {
        fprintf(stderr, "Error reading tasks from file.\n");
        free(tasks);
        *taskCount = -1; 
        tasks = NULL;
    }

    fclose(file);
    return tasks; 
}
void saveTasks(Task *tasks, int taskCount, const char *filename) {
    FILE *file = fopen(filename, "wb+");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing\n");
        return;
    }

    if (fwrite(tasks, sizeof(Task), taskCount, file) != taskCount) {
        fprintf(stderr, "Error writing to file\n");
    }

    fclose(file);
}