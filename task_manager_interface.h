#ifndef TASK_MANAGER_INTERFACE_H_INCLUDED
#define TASK_MANAGER_INTERFACE_H_INCLUDED
#include "structuries.h"
#include "language.h"

void menu(Language lang, MenuColors colors, Task task[], int taskCount);

void printTasks(Language lang, Task tasks[], int taskCount);

void scanTasks(Language lang, Task tasks[], int taskCount);

int deleteTasks(Language lang, Task tasks[], int taskCount);

void changeTasks(Language lang, Task tasks[], int taskCount);

void changeTask(Language lang, Task tasks[], int taskCount);

void printTaskStatus(Language lang, Task tasks[], int taskCount);

#endif // TASK_MANAGER_INTERFACE_H_INCLUDED
