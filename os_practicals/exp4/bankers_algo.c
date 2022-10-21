#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool allocation_possible();
void make_resource_request();

int main()
{
    int allocation[MAX][MAX], max[MAX][MAX], need[MAX][MAX], available[MAX], safe_sequence[MAX], process_completed[MAX];
    int total_processes, total_resources, total_processes_completed = 0, process = 0, skipped_processes = 0, i, j, copy_available[MAX], input;
    bool deadlock = false;

    printf("Enter the number of processes: ");
    scanf("%d", &total_processes);

    printf("Enter the total number of resources: ");
    scanf("%d", &total_resources);

    printf("Enter the number of allocated resource instances for each processes sequencially: \n");
    for (i = 0; i < total_processes; i++)
    {
        for (j = 0; j < total_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter the max number of resourceses that can be allocated for each process sequencially: \n");
    for (i = 0; i < total_processes; i++)
    {
        for (j = 0; j < total_resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the available instances of resources for each process sequencially: ");
    for (i = 0; i < total_resources; i++)
    {
        scanf("%d", &available[i]);
        copy_available[i] = available[i];
    }

    for (i = 0; i < total_processes; i++)
    {
        for (j = 0; j < total_resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
        // set process completed as zero (not completed).
        process_completed[i] = 0;
    }

    while (total_processes_completed != total_processes && deadlock != true)
    {
        if (allocation_possible(process, available, need, total_resources) == true && process_completed[process] == 0)
        {
            process_completed[process] = 1;
            safe_sequence[total_processes_completed] = process;
            total_processes_completed++;
            skipped_processes = 0;

            // Update the available array since some resources are released.
            for (j = 0; j < total_resources; j++)
            {
                available[j] += allocation[process][j];
            }
        }
        else
        {
            skipped_processes++;

            if (skipped_processes == total_processes)
            {
                deadlock = true;
            }
        }

        process++;
        if (process == total_processes)
        {
            process = 0;
        }
    }

    printf("\n");

    printf("Need matrix is : \n");
    for (i = 0; i < total_processes; i++)
    {
        for (j = 0; j < total_resources; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    if (deadlock == false)
    {
        printf("Safe sequence is : ");
        for (i = 0; i < total_processes; i++)
        {
            printf("P%d", safe_sequence[i]);
            if (i < total_processes - 1)
            {
                printf("->");
            }
        }
    }
    else
    {
        printf("System is in deadlock....");
    }

    printf("\n");

    while (true)
    {
        printf("\n1] Request resource");
        printf("\n0] Exit\n");

        scanf("%d", &input);

        if (input == 1)
        {

            printf("Enter the process number: ");
            scanf("%d", &process);

            make_resource_request(allocation[process], need[process], copy_available, total_resources, process);
        }
        else
        {
            break;
        }
    }

    printf("\n");
    return 0;
}

bool allocation_possible(int process, int *available, int need[MAX][MAX], int total_resources)
{
    bool possible = true;
    int i;

    for (i = 0; i < total_resources; i++)
    {
        if (need[process][i] > available[i])
        {
            possible = false;
        }
    }

    return possible;
}

void make_resource_request(int *allocation, int *need, int *available, int total_resources, int process)
{
    int input, request[MAX], i, count_need = -1, count_available = -1;
    printf("Enter the request for each %d resource(s) sequencially: ", total_resources);
    for (i = 0; i < total_resources; i++)
    {
        scanf("%d", &request[i]);
    }

    for (i = 0; i <= total_resources; i++)
    {
        if (request[i] <= need[i])
        {
            count_need++;
        }
        if (request[i] <= available[i])
        {
            count_available++;
        }
    }

    if (count_need != total_resources || count_available != total_resources)
    {
        printf("\nRequest for process P%d cannot be granted.\n", process);
        return;
    }
    else
    {
        for (i = 0; i < total_resources; i++)
        {
            need[i] = need[i] - request[i];
            available[i] = available[i] - request[i];
            allocation[i] = allocation[i] + request[i];
        }

        printf("\nResource granted!\n");
    }
}