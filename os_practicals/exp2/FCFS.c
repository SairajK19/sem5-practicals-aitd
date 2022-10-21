#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 100

float calculate_average(int *, int);

int main()
{
    int processes[MAX], burstTime[MAX], i, waitingTime[MAX], avg_waitingTime, turnAroundTime[MAX];
    int totalProcesses, time = 0, total;
    float avgTrunAroundTime;

    printf("Enter the total number of processes: ");
    scanf("%d", &totalProcesses);

    printf("Enter the bus time of processes sequencially: ");
    for (i = 0; i < totalProcesses; i++)
    {
        scanf("%d", &burstTime[i]);
    }

    time = 0;
    for (i = -1; i < totalProcesses; i++)
    {
        if (i == -1)
        {
            waitingTime[i + 1] = time;
        }
        else
        {
            time = time + burstTime[i];
            waitingTime[i + 1] = time;
        }
    }

    for (i = 0; i < totalProcesses; i++)
    {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

    printf("\nProcess  Burst Time   Waiting Time  Turn Around Time \n");
    for (i = 0; i < totalProcesses; i++)
    {
        printf("    %d          %d           %d                 %d       \n", i, burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    total = 0;
    for (i = 0; i < totalProcesses; i++)
    {
        total = total + waitingTime[i];
    }

    printf("\nAverage waiting time is %f. \n", calculate_average(waitingTime, totalProcesses));

    total = 0;
    for (i = 0; i < totalProcesses; i++)
    {
        total = total + turnAroundTime[i];
    }
    printf("Average Turn around time is %f. \n", calculate_average(turnAroundTime, totalProcesses));
}

float calculate_average(int *arr, int length)
{
    int i, total = 0;
    for (i = 0; i < length; i++)
    {
        total = total + arr[i];
    }

    return (float)total / (float)length;
}
