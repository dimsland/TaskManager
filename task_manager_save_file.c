#include <stdio.h>
#include "language.h"
#include "task_manager_save_file.h"
#include "task_manager_interface.h"
#include "structuries.h"
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Language changeLanguage(int selectLanguage) {
    Language lang;

    switch (selectLanguage) {
        case 1:
            lang = select_language("./English.lang");
            break;
        case 2:
            lang = select_language("./Deutsch.lang");
            break;
        default:
            printf("\033[0;35m Invalid choice. Defaulting to English.\033[0m\n");
            lang = select_language("./English.lang");
    }

    return lang;
}


Task *loadTasks(int *taskCount, const char *filename){
    if (taskCount == NULL) {
        fprintf(stderr, "Invalid task count pointer.\n");
        return NULL;
    }

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Task file not found. A new task list will be created.\n");
        *taskCount = 0;
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file); 
    if (fileSize < 0) {
        fprintf(stderr, "Error reading file size.\n");
        fclose(file);
        *taskCount = -1;
        return NULL;
    }
    rewind(file);

    *taskCount = fileSize / sizeof(Task);
    if (fileSize % sizeof(Task) != 0) {
        fprintf(stderr, "File size is not a multiple of task size.\n");
        fclose(file);
        *taskCount = -1;
        return NULL;
    }

    Task *tasks = (Task *) malloc(sizeof(Task) * (*taskCount));
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
        fclose(file);
        *taskCount = -1;
        return NULL;
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