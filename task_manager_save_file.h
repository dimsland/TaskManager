#ifndef TASK_MANAGER_SAVE_FILE_H_INCLUDED
#define TASK_MANAGER_SAVE_FILE_H_INCLUDED
#include "structuries.h"

Language changeLanguage(int selectLanguage);
void saveTasks(Task *tasks, int taskCount, const char *filename);
Task *loadTasks(int *taskCount, const char *filename);

#endif // TASK_MANAGER_SAVE_FILE_H_INCLUDED
