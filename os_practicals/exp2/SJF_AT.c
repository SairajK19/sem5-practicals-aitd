#include <stdio.h>

#define MAX 100

void sort_processes(int *, int *, int *, int);
int get_shortest_process(int *, int *, int, int, int);

struct process
{
	int burst_time;
	int arrival_time;
};

int main()
{
	/**
    * SJF with AT
	* Take processes from user.
	* Take the bus time.
    * Take the arrival time
	* print gantt chart.
	* calculate the waiting time, avg wating time, turn around time, avg turn around time.
	*/
	int processes[MAX], burst_time[MAX], arrival_time[MAX], i, waiting_time[MAX], avg_waiting_time, turn_around_time[MAX];
	int avg_turn_around_time, total_processes, ascii = 65, time = 0, process;

	printf("Enter the total number of processes: ");
	scanf("%d", &total_processes);

	for (i = 0; i < total_processes; i++)
	{
		printf("Enter the bus time of process %c \n", ascii + i);
		scanf("%d", &burst_time[i]);
		printf("Enter the Arrival time of process %c \n", ascii + i);
		scanf("%d", &arrival_time[i]);

		processes[i] = i;
	}

	// Sort based on arrival time.
	sort_processes(processes, burst_time, arrival_time, total_processes);
	printf("After Sorting\n");
	printf("| Processes | Burst Time | Arrival Time |\n");
	for (i = 0; i < total_processes; i++)
	{
		printf("|    %c      |     %d      |      %d       |\n", ascii + processes[i], burst_time[i], arrival_time[i]);
	}

	printf("\n\n| Processes | Burst Time | Arrival Time |\n");
	for (i = 0; i < total_processes; i++)
	{
		process = get_shortest_process(arrival_time, burst_time, i, total_processes, time);
		time = time + burst_time[process];
		// printf("\n Process %d has shortest bustime \n", process);
		printf("|    %c      |     %d      |      %d       |\n", ascii + processes[process], burst_time[process], arrival_time[process]);
	}

	return 0;
}

void swap(int *arr, int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void sort_processes(int *processes, int *burst_time, int *arrival_time, int total_processes)
{
	int i, j, temp;
	for (i = 0; i < total_processes; i++)
	{
		for (j = 0; j < total_processes - i - 1; j++)
		{
			if (arrival_time[j] > arrival_time[j + 1])
			{
				swap(arrival_time, j + 1, j);
				swap(processes, j + 1, j);
				swap(burst_time, j + 1, j);
			}
		}
	}
}

int get_shortest_process(int *time, int *burst_time, int current_index, int total_processes, int current_time)
{
	int min = 0, process = current_index;
	int process_with_shortest_bt[MAX], counter = 0, ascii = 65;

	// start iterating from the current process index.
	// check which of the processes have arrived and store them in an array.
	for (int i = current_index; i < total_processes; i++)
	{
		if (time[i] < current_time)
		{
			process_with_shortest_bt[counter] = i;
			counter++;
		}
	}

	printf("\n");
	for (int i = 0; i < counter; i++)
	{
		printf("%d ", process_with_shortest_bt[i]);
	}
	printf("\n");

	// From those processes get the process
	// which has the shortest bus time.
	for (int i = 0; i < counter; i++)
	{
		if (burst_time[process_with_shortest_bt[i]] < min)
		{
			min = process_with_shortest_bt[i];
			process = i;
		}
	}

	printf("Sending %c\n", process + ascii);
	return process;
}