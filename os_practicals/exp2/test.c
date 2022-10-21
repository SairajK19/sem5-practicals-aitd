#include <stdio.h>

#define MAX 100

int main()
{
    int processes[MAX], burst_time[MAX], arrival_time[MAX], waiting_time[MAX], turn_around_time[MAX];
    int total_processes, i, j, time;

    printf("Enter the total number of processes: ");
    scanf("%d", &total_processes);

    printf("Enter the burst time of processes sequencially: ");
    for (i = 0; i < total_processes; i++)
    {
        scanf("%d", &burst_time[i]);
        processes[i] = i;
    }

    printf("Enter the arrival time of processes sequencially: ");
    for ( i = 0; i < total_processes; i++)
    {
        scanf("%d", &arrival_time[i]);
    }
    

    return 0;
}