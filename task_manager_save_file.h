#ifndef TASK_MANAGER_SAVE_FILE_H_INCLUDED
#define TASK_MANAGER_SAVE_FILE_H_INCLUDED
#include "structuries.h"

void changeLanguage(int selectLanguage, FunctionPointers *fp);
void saveTasks(Task *tasks, int taskCount, const char *filename);
Task* loadTasks(int *taskCount, const char *filename);

#endif // TASK_MANAGER_SAVE_FILE_H_INCLUDED
