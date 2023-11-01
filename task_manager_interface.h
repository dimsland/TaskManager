#ifndef TASK_MANAGER_INTERFACE_H_INCLUDED
#define TASK_MANAGER_INTERFACE_H_INCLUDED
#include "structuries.h"

void menu(Task task[], int taskCount);

void printTasks(Task tasks[], int taskCount);

void scanTasks(Task tasks[], int taskCount);

int deleteTasks(Task tasks[], int taskCount);

void changeTasks(Task tasks[], int taskCount);

void changeTask(Task tasks[], int taskCount);

void printTaskStatus(Task tasks[], int taskCount);





#endif // TASK_MANAGER_INTERFACE_H_INCLUDED
