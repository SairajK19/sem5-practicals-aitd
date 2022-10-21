#include <stdio.h>

#define MAX 100

int main()
{
    int burst_time[MAX], processes[MAX], total_processes, i, j, waiting_time[MAX] = {0}, temp = 0;
    float average_waiting_time = 0, average_turn_around_time = 0;

    printf("\nNumber of Processes: ");
    scanf("%d", &total_processes);

    printf("\nEnter burst time of each processes sequencially: ");
    for (i = 0; i < total_processes; i++)
    {
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    processes[i] = i;

    for (i = 0; i < total_processes - 1; i++)
    {
        for (j = 0; j < total_processes - i - 1; j++)
        {
            if (burst_time[j] > burst_time[j + 1])
            {
                temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    for (i = 1; i <= total_processes; i++)
    {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }

    printf("\n\nWaiting time \n");
    for (i = 0; i < total_processes; i++)
    {
        printf("P%d->%d\n", processes[i], waiting_time[i]);
    }

    for (i = 0; i < total_processes; i++)
    {
        average_waiting_time += waiting_time[i];
    }

    average_waiting_time /= total_processes;

    printf("\n\nAverage Waiting Time is %f \n", average_waiting_time);

    printf("\n\nTurn Around Time \n");
    for (i = 0; i < total_processes; i++)
    {
        printf("P%d->%d\n", processes[i], waiting_time[i] + burst_time[i]);
    }

    for (i = 0; i < total_processes; i++)
    {
        average_turn_around_time += waiting_time[i] + burst_time[i];
    }

    average_turn_around_time /= total_processes;
    printf("\n\nAverage Turn Around Time is %f \n\n", average_turn_around_time);

    return 0;
}