#ifndef STRUCTURIES_H_INCLUDED
#define STRUCTURIES_H_INCLUDED

typedef struct
{
    int day, month, year;
} Date;

typedef enum
{
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
} Status;

typedef struct
{
    char description[100];
    int priority;
    Status status;
    Date deadline;
} Task;

typedef struct FunctionPointers
{
    void (*menu)(Task[], int);
    void (*printTasks)(Task[], int);
    void (*scanTasks)(Task[], int);
    int (*deleteTasks)(Task[], int);
    void (*changeTasks)(Task[], int);
    void (*changeTask)(Task[], int);
    void (*printTaskStatus)(Task[], int);
} FunctionPointers;

#endif // STRUCTURIES_H_INCLUDED
