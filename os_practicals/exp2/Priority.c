// exp2.5.c Priority
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX 100

int sort_processes(int *, int *, int*, int);
void swap(int *, int , int );
float calculate_average(int *, int);

int main()
{
	int processes[MAX], burst_time[MAX], priority[MAX], waiting_time[MAX], avg_waiting_time, turn_around_time[MAX];;
	int avg_turn_around_time = 0,ascii = 65, time = 0, total_processes = 0, i, j;

	printf("Enter the total number of processes.\n");
	scanf("%d", &total_processes);

    printf("\nEnter burst time of each processes sequencially: ");
    for (i = 0; i < total_processes; i++)
    {
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    printf("\nEnter priority of each processes sequencially: ");
    for (i = 0; i < total_processes; i++)
    {
        scanf("%d", &priority[i]);
        processes[i] = i + 1;
    }

	printf("Sorting  based on priority.\n");
	sort_processes(processes, burst_time, priority, total_processes);

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
			printf("%d ", 0);
			waiting_time[i + 1] = time;
		}
		else
		{
			printf("%d ", time + burst_time[i]);
			time = time + burst_time[i];
			waiting_time[i + 1] = time;
		}
	}

	printf("\n\nWaiting time is \n");

	for (i = 0; i < total_processes; i++)
	{
		printf("Process %c -> %d.\n", ascii + processes[i], waiting_time[i]);
	}

	printf("Average waiting time is %f. \n", calculate_average(waiting_time, total_processes));
	printf("\n\nTurn around time is \n");

	for (i = 0; i < total_processes; i++)
	{
		printf("Process %c -> %d. \n", ascii + processes[i], burst_time[i] + waiting_time[i]);
		turn_around_time[i] = burst_time[i] + waiting_time[i];
	}

	printf("Average Turn around time is %f. \n", calculate_average(turn_around_time, total_processes));
}

int sort_processes(int *processes, int *burst_time, int *priority, int total_processes)
{
	int temp, i ,j;
	for (i = 0; i < total_processes - 1; i++)
	{
		for (j = 0; j < total_processes - i - 1; j++)
		{
			if (priority[j] > priority[j+1])
			{
				swap(priority, j+1, j);
				swap(burst_time, j+1, j);
				swap(processes, j+1, j);
			}		
		}
	}
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

void swap(int *arr, int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
