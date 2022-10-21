#include <stdio.h>

int min();
int max();
void fcfs();

#define MAX 100

int main()
{
    int sequence[MAX], total_blocks, i, j;

    printf("Enter the total blocks to be scheduled: ");
    scanf("%d", &total_blocks);

    printf("Enter the block sequence: ");
    for (i = 0; i < total_blocks; i++)
    {
        scanf("%d", &sequence[i]);
    }

    printf("Sequence is: ");
    for (i = 0; i < total_blocks; i++)
    {
        printf("%d ", sequence[i]);
    }

    fcfs(sequence, &total_blocks);

    return 0;
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void fcfs(int *sequence, int *total_blocks)
{
    int previous = 0, current = 0, total_head_movement = 0, low, high, i;

    printf("\n\nEnter current head: ");
    scanf("%d", &previous);

    for (i = 0; i < *total_blocks; i++)
    {
        current = sequence[i];
        low = min(previous, current);
        high = max(previous, current);
        total_head_movement += (high - low);
        previous = sequence[i];
    }

    printf("Total head movement is %d\n", total_head_movement);
}