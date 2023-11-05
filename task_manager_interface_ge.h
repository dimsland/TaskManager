#ifndef TASK_MANAGER_INTERFACE_GE_H_INCLUDED
#define TASK_MANAGER_INTERFACE_GE_H_INCLUDED
#include "structuries.h"

void menu_ge(Task task[], int taskCount);

void printTasks_ge(Task tasks[], int taskCount);

void scanTasks_ge(Task tasks[], int taskCount);

int deleteTasks_ge(Task tasks[], int taskCount);

void changeTasks_ge(Task tasks[], int taskCount);

void changeTask_ge(Task tasks[], int taskCount);

void printTaskStatus_ge(Task tasks[], int taskCount);

#endif // TASK_MANAGER_INTERFACE_GE_H_INCLUDED
