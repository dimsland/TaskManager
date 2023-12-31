#include <stdio.h>
#include <stdlib.h>

#include "file_manager.h"

Task *loadTasks(int *taskCount, const char *filename)
{
    if (taskCount == NULL)
    {
        perror("Invalid task count pointer");
        return NULL;
    }

    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Task file not found. A new task list will be created");
        *taskCount = 0;
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize < 0)
    {
        perror("Error reading file size");
        fclose(file);
        *taskCount = -1;
        return NULL;
    }
    rewind(file);

    *taskCount = fileSize / sizeof(Task);
    if (fileSize % sizeof(Task) != 0)
    {
        perror("File size is not a multiple of task size");
        fclose(file);
        *taskCount = -1;
        return NULL;
    }

    Task *tasks = (Task *)malloc(sizeof(Task) * (*taskCount));
    if (tasks == NULL)
    {
        perror("Memory allocation failed");
        fclose(file);
        *taskCount = -1;
        return NULL;
    }

    size_t tasksRead = fread(tasks, sizeof(Task), *taskCount, file);
    if (tasksRead != *taskCount)
    {
        perror("Error reading tasks from file");
        free(tasks);
        fclose(file);
        *taskCount = -1;
        return NULL;
    }

    fclose(file);
    return tasks;
}

void saveTasks(Task *tasks, int taskCount, const char *filename)
{
    FILE *file = fopen(filename, "wb+");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    if (fwrite(tasks, sizeof(Task), taskCount, file) != taskCount)
    {
        perror("Error writing to file");
    }

    fclose(file);
}
