// RR

// RR Pre-Emptive Algorithm.
#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int main()
{
    /*
	p1 -> 5
	p2 -> 10
	p3 -> 22
	
	slice = 2
	
	p1 -> 0 2
	p2 -> 2 4
	p3 -> 4 6
	
	*/
    int time_quantum, processes[MAX], burst_time[MAX], waiting_time[MAX], remaining_burst_time[MAX], turn_around_time[MAX];
    int ascii = 65, total_processes, i, j, current_time = 0;
    bool done = false;

    printf("Enter the total number of processes.\n");
    scanf("%d", &total_processes);

    printf("Enter burst time of process");
    for (j = 0; j < total_processes; j++)
    {
        printf(" %c ", ascii + j);
    }
    printf(": ");
    for (i = 0; i < total_processes; i++)
    {

        scanf("%d", &burst_time[i]);

        processes[i] = i;
        remaining_burst_time[i] = burst_time[i];
        waiting_time[i] = 0;
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &time_quantum);

    while (true)
    {
        for (i = 0; i < total_processes; i++)
        {
            if (remaining_burst_time[i] > 0)
            {
                done = false;
            }

            if (remaining_burst_time[i] >= time_quantum)
            {
                remaining_burst_time[i] -= time_quantum;

                for (j = 0; j < total_processes; j++)
                {
                    if (j != i)
                    {
                        waiting_time[j] += time_quantum;
                    }
                }

                current_time += time_quantum;
            }

            else if (remaining_burst_time[i] < time_quantum)
            {
                // direct print, dont decrement
                remaining_burst_time[i] = 0;

                current_time += time_quantum;
            }

            if (remaining_burst_time[i] <= 0)
            {
                done = true;
            }
        }

        if (done)
        {
            break;
        }
    }

    printf("Process | Burst Time | Waiting Time | Turn Around Time \n");
    for (i = 0; i < total_processes; i++)
    {
        printf("%c       | %d         | %d           | %d              \n", processes[i] + ascii, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    printf("\n");
    return 0;
}