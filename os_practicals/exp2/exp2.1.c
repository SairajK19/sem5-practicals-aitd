#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 100

int calculate_average(int *, int);

int main()
{
    /**
     * Take processes from user.
     * Take the bus time.
     * print gantt chart.
     * calculate the waiting time, avg wating time, turn around time, avg turn around time.
    */

    int processes[MAX], bustime[MAX], i, waiting_time[MAX], avg_waiting_time, turn_around_time[MAX];
    int avg_turn_around_time, total_processes, ascii = 65, time = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &total_processes);

    for (i = 0; i < total_processes; i++)
    {
        printf("Enter the bus time of process %c \n", ascii + i);
        scanf("%d", &bustime[i]);
    }

    printf("\nPrinting Gantt chart.\n");
    for (i = 0; i < total_processes; i++)
    {
        printf("| %c ", ascii + i);
    }
    printf("|\n");

    time = 0;
    for (i = -1; i < total_processes; i++)
    {
        if (i == -1)
        {
            printf("%d   ", 0);
            waiting_time[i + 1] = time;
        }
        else
        {
            printf("%d   ", time + bustime[i]);
            time = time + bustime[i];
            waiting_time[i + 1] = time;
        }
    }

    printf("\n\nWaiting time is \n");
    for (i = 0; i < total_processes; i++)
    {
        printf("Process %c -> %d.\n", ascii + i, waiting_time[i]);
    }

    printf("Average waiting time is %d. \n", calculate_average(waiting_time, total_processes));

    printf("\n\nTurn around time is \n");
    for (i = 0; i < total_processes; i++)
    {
        printf("Process %c -> %d. \n", ascii + i, bustime[i] + waiting_time[i]);
        turn_around_time[i] = bustime[i] + waiting_time[i];
    }

    printf("Average Turn around time is %d. \n", calculate_average(turn_around_time, total_processes));
}

int calculate_average(int *arr, int length)
{
    int i, total = 0;
    for (i = 0; i < length; i++)
    {
        total = total + arr[i];
    }

    return total / length;
}