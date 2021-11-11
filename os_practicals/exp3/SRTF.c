#include <stdio.h>

void main()
{
    int arrival_time[10], burst_time[10], copy_bt[10], porcesses[10], min, count = 0, waiting_time[10] = {0}, turn_around_time[10] = {0}, total_processes, time, i, end;
    float ttAvg = 0, wtAvg = 0;
    printf("\nNumber of Processes: ");
    scanf("%d", &total_processes);

    printf("\nBurst time of each: ");
    for (i = 0; i < total_processes; i++)
    {
        scanf("%d", &burst_time[i]);
        copy_bt[i] = burst_time[i];
        porcesses[i] = i;
    }

    printf("\nArrival Time of each: ");
    for (i = 0; i < total_processes; i++)
        scanf("%d", &arrival_time[i]);

    burst_time[9] = 100;

    printf("\n\nProcess   Waitingtime   Turn Around Time\n");
    for (time = 0; count != total_processes; time++)
    {
        min = 9;
        for (i = 0; i <= total_processes; i++)
        {
            if (arrival_time[i] <= time && burst_time[i] < burst_time[min] && burst_time[i] > 0)
                min = i;
        }
        burst_time[min]--;
        if (burst_time[min] == 0)
        {
            count++;
            end = time + 1;
            waiting_time[min] = end - arrival_time[min] - copy_bt[min];
            wtAvg = wtAvg + waiting_time[min];
            turn_around_time[min] = end - burst_time[min] - arrival_time[min];
            ttAvg = ttAvg + turn_around_time[min];

            printf("P%d       	%d            	%d\n", porcesses[min] + 1, waiting_time[min], turn_around_time[min]);
        }
    }

    ttAvg /= total_processes;
    wtAvg /= total_processes;

    printf("\n\nWaiting Time Average: %f", wtAvg);
    printf("\nTurn Around Time Average: %f\n\n", ttAvg);
}
