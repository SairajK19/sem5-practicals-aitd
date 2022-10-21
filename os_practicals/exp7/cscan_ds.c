#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define START 0
#define END 199

int cscan(int *, int);
void sort(int *, int);

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

    printf("Sequence is: "); // 98 183 37 122 14 124 65 67
    for (i = 0; i < total_blocks; i++)
    {
        printf("%d ", sequence[i]);
    }

    printf("\nTotal head movement is %d", cscan(sequence, total_blocks));

    printf("\n");
    return 0;
}

void sort(int *arr, int arr_length)
{
    int i, j, temp;
    for (i = 0; i < arr_length - 1; i++)
    {
        for (j = 0; j < arr_length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int cscan(int *sequence, int total_blocks)
{
    int initial_head, previous_head, current_head, i, j, total_head_movement = 0;
    int below_head, above_head;
    printf("\nEnter the initial head position: ");
    scanf("%d", &initial_head);

    previous_head = initial_head;
    current_head = initial_head;

    sort(sequence, total_blocks);

    printf("\nSequence is: ");
    for (i = 0; i < total_blocks; i++)
    {
        if (sequence[i] > initial_head)
        {
            for (j = i - 1; j >= 0; j--)
            {
                printf("%d ", sequence[j]);
                current_head = sequence[j];
                total_head_movement += abs(current_head - previous_head);
                previous_head = current_head;
            }

            // Move till zero
            printf("%d ", START);
            current_head = START;
            total_head_movement += abs(current_head - previous_head);
            previous_head = current_head;

            printf("%d ", END);
            current_head = END;
            total_head_movement += abs(current_head - previous_head);
            previous_head = current_head;

            for (j = total_blocks - 1; j >= i; j--)
            {
                printf("%d ", sequence[j]);
                current_head = sequence[j];
                total_head_movement += abs(current_head - previous_head);
                previous_head = current_head;
            }
            break;
        }
    }

    return total_head_movement;
}
