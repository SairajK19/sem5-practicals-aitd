#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    int burst_time;
    int arrival_time;
    int process_number;
    bool ended;
} process;

void sort_processes(process *, int);
process get_shortest_process(process *, int, int, int);

int main()
{
    process processes[MAX], res_process, temp;
    int i, ascii = 65, time = 0, total_processes;

    printf("Enter the total number of processes: ");
    scanf("%d", &total_processes);

    for (i = 0; i < total_processes; i++)
    {
        printf("Enter the burst time of process %c \n", ascii + i);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the Arrival time of process %c \n", ascii + i);
        scanf("%d", &processes[i].arrival_time);

        processes[i].process_number = i;
        processes[i].ended = false;
    }

    // Sort based on arrival time.
    sort_processes(processes, total_processes);

    printf("After Sorting\n");
    printf("| Processes | Burst Time | Arrival Time |\n");
    for (i = 0; i < total_processes; i++)
    {
        printf("|    %d      |     %d      |      %d       |\n", processes[i].process_number, processes[i].burst_time, processes[i].arrival_time);
    }

    for (i = 0; i < total_processes; i++)
    {
        if (time < processes[i].arrival_time || time == 0)
            time = processes[i].arrival_time;

        for (int j = 0; j < total_processes; j++)
        {
            for (int k = 0; k < total_processes - j - 1; k++)
            {
                if (processes[k].burst_time > processes[k + 1].burst_time && (processes[k].burst_time <= time || processes[k + 1].burst_time <= time))
                {
                    temp = processes[k+1];
                    processes[k + 1] = processes[k];
                    processes[k] = temp;
                }
            }
        }
    }

    printf("\n\n| Processes | Burst Time | Arrival Time |\n");
    for (i = 0; i < total_processes; i++)
    {
        printf("|    %d      |     %d      |      %d       |\n", processes[i].process_number, processes[i].burst_time, processes[i].arrival_time);
    }
}

void swap(process *arr, int x, int y)
{
    process temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void sort_processes(process *processes, int total_processes)
{
    int i, j, temp;
    for (i = 0; i < total_processes; i++)
    {
        for (j = 0; j < total_processes - i - 1; j++)
        {
            if (processes[j].arrival_time > processes[j + 1].arrival_time)
            {
                swap(processes, j + 1, j);
            }
        }
    }
}