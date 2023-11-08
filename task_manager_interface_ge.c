#include "task_manager_interface_ge.h"
#include <stdio.h>
#include <strings.h>

void menu_ge(Task tasks[], int taskCount)
{
    printf("-----[Menü]------\n");
    printf("\033[0;31m1.Aufgabe hinzufügen\033[0m\n");
    printf("\033[0;33m2.Aufgabe löschen\033[0m\n");
    printf("\033[0;32m3.Status der Aufgabe ändern\033[0m\n");
    printf("\033[0;34m4.Status der Aufgaben ändern\033[0m\n");
    printf("\033[0;35m5.Alle Aufgaben anzeigen\033[0m\n");
    printf("\033[0;36m6.Aufgabe und Status anzeigen\033[0m\n");
    printf("\033[0;31m0.Beenden\033[0m\n");
    printf("Nummer: ");
}

void printTasks_ge(Task tasks[], int taskCount)
{
    printf("Aufgaben-Manager:\n");
    printf("---------------------------------------------------------\n");
    printf("   Aufgabe |     Fälligkeitsdatum | Priorität | Status   \n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < taskCount; i++)
    {
        printf("%-20s %02d.%02d.%04d %10d ", tasks[i].description, tasks[i].deadline.day, tasks[i].deadline.month, tasks[i].deadline.year, tasks[i].priority);
        if (tasks[i].status == NEW)
        {
            printf("NEU\n");
        }
        else if (tasks[i].status == IN_PROGRESS)
        {
            printf("BEARBEITUNG\n");
        }
        else if (tasks[i].status == TESTING)
        {
            printf("BEWERTUNG\n");
        }
        else if (tasks[i].status == DONE)
        {
            printf("ERLEDIGT\n");
        }
        else
        {
            printf("NEU\n");
        }
    }

    printf("---------------------------------------------------------\n");
}

void printTaskStatus_ge(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int todoCount = 0;
        int doneCount = 0;
        for (int i = 0; i < taskCount; i++)
        {
            if (tasks[i].status == DONE)
            {
                doneCount++;
            }
            else
            {
                todoCount++;
            }
        }
        printf("Aufgaben:\n");
        printf("Bearbeitung: %d\n", todoCount);
        printf("Erledigt: %d\n", doneCount);
    }
    else
    {
        printf("Keine Aufgaben anzuzeigen.\n");
    }
}

void scanTasks_ge(Task tasks[], int taskCount)
{
    Task newTask;
    printf("Beschreibung: ");
    scanf(" %[^\n]", newTask.description);
    printf("Priorität (1-5): ");
    scanf("%d", &newTask.priority);
    newTask.status = NEW;
    printf("Status (NEU, BEARBEITUNG, BEWERTUNG, ERLEDIGT): ");
    char state[20];
    scanf(" %s", state);
    if (strcasecmp(state, "NEU") == 0)
    {
        newTask.status = NEW;
    }
    else if (strcasecmp(state, "BEARBEITUNG") == 0)
    {
        newTask.status = IN_PROGRESS;
    }
    else if (strcasecmp(state, "BEWERTUNG") == 0)
    {
        newTask.status = TESTING;
    }
    else if (strcasecmp(state, "ERLEDIGT") == 0)
    {
        newTask.status = DONE;
    }
    else
    {
        printf("Ungültiger Status. 'NEU' wird als Standard gesetzt.\n");
        newTask.status = NEW;
    }

    printf("Fälligkeitsdatum(TAG.MONAT.JAHR): ");
    scanf(" %d.%d.%d", &newTask.deadline.day, &newTask.deadline.month, &newTask.deadline.year);
    tasks[taskCount - 1] = newTask;
    taskCount++;
    printf("Aufgabe hinzugefügt.\n");
}

int deleteTasks_ge(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int deleteIndex;
        printTasks_ge(tasks, taskCount);
        printf("Geben Sie den Index ein");
        if (taskCount > 0)
        {
            int changeIndex;
            printTasks_ge(tasks, taskCount);
            printf("Geben Sie den Index der Aufgabe ein, um den Status zu ändern: ");
            scanf("%d", &changeIndex);

            if (changeIndex >= 0 && changeIndex < taskCount)
            {
                tasks[changeIndex].status = (tasks[changeIndex].status == NEW) ? IN_PROGRESS : NEW;
                printf("Status der Aufgabe am Index %d geändert.\n", changeIndex);
            }
            else
            {
                printf("Ungültiger Index.\n");
            }
        }
        else
        {
            printf("Keine Aufgaben zum Statuswechsel.\n");
        }

        scanf("%d", &deleteIndex);

        if (deleteIndex >= 0 && deleteIndex < taskCount)
        {
            for (int i = deleteIndex; i < taskCount - 1; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            taskCount--;
            printf("Aufgabe am Index %d gelöscht.\n", deleteIndex);
        }
        else
        {
            printf("Ungültiger Index.\n");
        }
    }
    else
    {
        printf("Keine Aufgaben zum Löschen.\n");
    }
    return taskCount;
}

void changeTasks_ge(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        int changeIndex;
        printTasks_ge(tasks, taskCount);
        printf("Geben Sie den Index der Aufgabe ein, um den Status zu ändern: ");
        scanf("%d", &changeIndex);

        if (changeIndex >= 0 && changeIndex < taskCount)
        {
            tasks[changeIndex].status = (tasks[changeIndex].status == NEW) ? IN_PROGRESS : NEW;
            printf("Status der Aufgabe am Index %d geändert.\n", changeIndex);
        }
        else
        {
            printf("Ungültiger Index.\n");
        }
    }
    else
    {
        printf("Keine Aufgaben zum Statuswechsel.\n");
    }
}

void changeTask_ge(Task tasks[], int taskCount)
{
    if (taskCount > 0)
    {
        for (int i = 0; i < taskCount; i++)
        {
            tasks[i].status = DONE;
        }
        printf("Alle Aufgaben auf 'ERLEDIGT' gesetzt.\n");
    }
    else
    {
        printf("Keine Aufgaben zum Statuswechsel.\n");
    }
}
