#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

int calculate_average(int *, int);
void sort_processes(int, int *, int *, int *);

int main()
{
    /**
     * FCFS with AT
     * Take processes from user.
     * Take the bus time.
     * sort processes based on arrival time.
     * print gantt chart.
     * calculate the waiting time, avg wating time, turn around time, avg turn around time.
    */

    int processes[MAX], bustime[MAX], arrival_time[MAX], i, waiting_time[MAX], avg_waiting_time, turn_around_time[MAX];
    int avg_turn_around_time, total_processes, ascii = 65, time = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &total_processes);

    for (i = 0; i < total_processes; i++)
    {
        printf("Enter the bus time of process %c \n", ascii + i);
        scanf("%d", &bustime[i]);
        printf("Enter the arrival time for process %c \n", ascii + i);
        scanf("%d", &arrival_time[i]);
        processes[i] = i;
    }

    sort_processes(total_processes, bustime, arrival_time, processes);

    printf("\nPrinting Gantt chart.\n");
    for (i = 0; i < total_processes; i++)
    {
        printf("| %c ", ascii + processes[i]);
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
        printf("Process %c -> %d.\n", ascii + processes[i], waiting_time[i]);
    }

    printf("Average waiting time is %d. \n", calculate_average(waiting_time, total_processes));

    printf("\n\nTurn around time is \n");
    for (i = 0; i < total_processes; i++)
    {
        printf("Process %c -> %d. \n", ascii + processes[i], bustime[i] + waiting_time[i]);
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

void swap(int *arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void sort_processes(int total_processes, int *bustime, int *arrival_time, int *processes)
{
    int i, j, temp, low = 0, high = total_processes - 1;

    for (i = 0; i < total_processes - 1; i++)
    {
        for (j = 0; j < total_processes - i - 1; j++)
        {
            if (arrival_time[j] > arrival_time[j + 1])
            {
                swap(arrival_time, j + 1, j);
                swap(bustime, j + 1, j);
                swap(processes, j+1, j);
            }
        }
    }
}