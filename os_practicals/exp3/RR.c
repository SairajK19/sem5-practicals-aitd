#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int i, total_process, q, t = 0;
    int burst_time[10], waiting_time[10], turn_around_time[10], processes[10], remaining_burst_time[20];

    float awt = 0.0, att = 0.0;
    printf("Enter the number of processes:  ");
    scanf("%d", &total_process);

    for (i = 0; i < total_process; i++)
    {
        printf("Enter the Process and Burst time: ");
        scanf("%d %d", &processes[i], &burst_time[i]);
    }

    printf("Enter the time slice: ");
    scanf("%d", &q);

    for (i = 0; i < total_process; i++)
        remaining_burst_time[i] = burst_time[i];

    while (1)
    {
        bool done = true;
        for (i = 0; i < total_process; i++)
        {
            if (remaining_burst_time[i] > 0)
            {
                done = false;
                if (remaining_burst_time[i] > q)
                {
                    t = t + q;
                    remaining_burst_time[i] = remaining_burst_time[i] - q;
                }
                else
                {
                    t = t + remaining_burst_time[i];
                    waiting_time[i] = t - burst_time[i];
                    awt = awt + waiting_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }

    for (i = 0; i < total_process; i++)
    {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
        att = att + turn_around_time[i];
    }

    printf("\n\tProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for (i = 0; i < total_process; i++)
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", processes[i], burst_time[i], waiting_time[i], turn_around_time[i]);

    printf("\nAverage waiting time is %f", awt / total_process);
    printf("\nAverage turnaround time is %f", att / total_process);

    return 0;
}
