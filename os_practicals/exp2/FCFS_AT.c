#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 100

float calculate_average(int *, int);

int main()
{
    int processes[MAX], burstTime[MAX], arrivalTime[MAX], i, waitingTime[MAX], avgWaitingTime, turnAroundTime[MAX];
    int avgTurnAroundTime, totalProcesses, time = 0;
    int temp;

    printf("Enter the total number of processes: ");
    scanf("%d", &totalProcesses);

    printf("Enter the burst time of processes: ");
    for (i = 0; i < totalProcesses; i++)
    {
        scanf("%d", &burstTime[i]);
        processes[i] = i;
    }

    printf("\nEnter the arrival time of processes: ");
    for (i = 0; i < totalProcesses; i++)
    {
        scanf("%d", &arrivalTime[i]);
    }

    for (i = 0; i < totalProcesses - 1; i++)
    {
        for (int j = 0; j < totalProcesses - i - 1; j++)
        {
            if (arrivalTime[j] > arrivalTime[j + 1])
            {                
                temp = arrivalTime[j + 1];
    			arrivalTime[j + 1] = arrivalTime[j];
    			arrivalTime[j] = temp;
                
                temp = burstTime[j + 1];
    			burstTime[j + 1] = burstTime[j];
    			burstTime[j] = temp;
                
                temp = processes[j + 1];
    			processes[j + 1] = processes[j];
    			processes[j] = temp;
            }
        }
    }

    printf("\nPrinting Gantt chart.\n");
    for (i = 0; i < totalProcesses; i++)
    {
        printf("| %d ", processes[i]);
    }
    printf("|\n");

    time = 0;
    for (i = -1; i < totalProcesses; i++)
    {
        if (i == -1)
        {
            printf("%d   ", 0);
            waitingTime[i + 1] = time;
        }
        else
        {
            printf("%d   ", time + burstTime[i]);
            time = time + burstTime[i];
            waitingTime[i + 1] = time - arrivalTime[i+1];
        }
    }

    printf("\n\nWaiting time is \n");
    for (i = 0; i < totalProcesses; i++)
    {
        printf("Process %d -> %d.\n", processes[i], waitingTime[i]);
    }
    
    int total = 0;
    for (i = 0; i < totalProcesses; i++)
    {
        total = total + waitingTime[i];
    }

    printf("Average waiting time is %d. \n", (float)total / (float)totalProcesses);

    printf("\n\nTurn around time is \n");
    for (i = 0; i < totalProcesses; i++)
    {
        printf("Process %d -> %d. \n", processes[i], burstTime[i] + waitingTime[i]);
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
    
    for (i = 0; i < totalProcesses; i++)
    {
        total = total + turnAroundTime[i];
    }

    printf("Average Turn around time is %f. \n", (float)total / (float)totalProcesses);
}
