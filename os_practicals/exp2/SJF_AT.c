#include <stdio.h>

int main()
{
	int i, j, n, min, k = 1, btime = 0, ASCII = 65;
	float wavg = 0, tavg = 0, tsum = 0, wsum = 0;
	int process[99], burst_time[99], temp, arrival_time[99], waiting_time[99], turn_arround_time[99], ta = 0, sum = 0;

	printf("\nEnter the number of process:");
	scanf("%d", &n);


	printf("\nEnter Burst time of processes sequentially:");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &burst_time[i]);

		process[i] = ASCII + i;
	}

	printf("\nEnter arrival time of processes sequentially:");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arrival_time[i]);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arrival_time[i] < arrival_time[j])
			{
				temp = process[j];
				process[j] = process[i];
				process[i] = temp;

				temp = arrival_time[j];
				arrival_time[j] = arrival_time[i];
				arrival_time[i] = temp;

				temp = burst_time[j];
				burst_time[j] = burst_time[i];
				burst_time[i] = temp;
			}
		}
	}

	for (j = 0; j < n; j++)
	{
		btime = btime + burst_time[j];
		min = burst_time[k];
		for (i = k; i < n; i++)
		{
			if (btime >= arrival_time[i] && burst_time[i] < min)
			{
				temp = process[k];
				process[k] = process[i];
				process[i] = temp;

				temp = arrival_time[k];
				arrival_time[k] = arrival_time[i];
				arrival_time[i] = temp;

				temp = burst_time[k];
				burst_time[k] = burst_time[i];
				burst_time[i] = temp;
			}
		}
		k++;
	}
	waiting_time[0] = 0;
	for (i = 1; i < n; i++)
	{
		sum = sum + burst_time[i - 1];
		waiting_time[i] = sum - arrival_time[i];
		wsum = wsum + waiting_time[i];
	}

	wavg = (wsum / n);
	for (i = 0; i < n; i++)
	{
		ta = ta + burst_time[i];
		turn_arround_time[i] = ta - arrival_time[i];
		tsum = tsum + turn_arround_time[i];
	}

	tavg = (tsum / n);

	printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around");
	for (i = 0; i < n; i++)
	{
		printf("\n %c\t %d\t %d\t\t %d\t\t\t%d", process[i], burst_time[i], arrival_time[i], waiting_time[i], turn_arround_time[i]);
	}

	printf("\nAverage Waiting time: %f", wavg);
	printf("\nAverage turn arround time : %f", tavg);
	return 0;
}