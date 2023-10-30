#ifndef STRUCTURIES_H_INCLUDED
#define STRUCTURIES_H_INCLUDED

typedef struct {
    int day, month, year;
} Date;

typedef enum {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
} Status;

struct Task {
    char description[100];
    int priority;
    Status status;
    Date deadline;
};

#endif // STRUCTURIES_H_INCLUDED

