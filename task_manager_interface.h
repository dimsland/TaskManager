#ifndef TASK_MANAGER_INTERFACE_H_INCLUDED
#define TASK_MANAGER_INTERFACE_H_INCLUDED
#include "structuries.h"

void printTasks(struct Task tasks[], int taskCount);

void scanTasks(struct Task tasks[], int* taskCount);

void deleteTasks(struct Task tasks[], int* taskCount);

void changeTasks(struct Task tasks[], int* taskCount);

void changeTask(struct Task tasks[], int* taskCount);

#endif // TASK_MANAGER_INTERFACE_H_INCLUDED

