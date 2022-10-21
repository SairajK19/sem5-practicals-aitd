#include <stdio.h>
#include <stdlib.h>

void sstf(int *, int *);
int get_shortest_seek(int *, int *, int, int, int);

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

    sstf(sequence, &total_blocks);

    return 0;
}

void sstf(int *sequence, int *total_blocks)
{
    int head_position, current, previous, total_head_movement = 0, temp=0, index, len_g=0, len_s=0;
    int greater[*total_blocks], smaller[*total_blocks], blocks_covered=0;

    printf("\nEnter starting position: ");
    scanf("%d", &head_position);
    current = head_position;
    previous = current;
    
    while(blocks_covered != *total_blocks)
    {
        temp = 0;
        for (int i = 0; i < *total_blocks; i++)
        {
            if (sequence[i] > current)
            {
                greater[temp] = sequence[i];
                len_g++;
                temp++;
            }
        }

        temp = 0;
        for (int i = 0; i < *total_blocks; i++)
        {
            if (sequence[i] < current)
            {
                smaller[temp] = sequence[i];
                len_s++;
                temp++;
            }
        }

        current = get_shortest_seek(greater, smaller, current, len_s, len_g);
        
        for (int i = 0; i < *total_blocks; i++)
        {
            if (sequence[i] == current)
            {
                sequence[i] = -1;
            }
        }

        total_head_movement += abs(current - previous);
        previous = current;

        blocks_covered++;
        len_s=0;
        len_g=0;
    }

    printf("\nTotal head movement is: %d\n", total_head_movement);
}

int get_shortest_seek(int *greater, int *smaller, int current, int len_s, int len_g)
{
    int gmin = 1000, smax = -1;

    for (int i = 0; i < len_g; i++)
    {
        if (greater[i] < gmin && greater[i] != -1)
        {
            gmin = greater[i];
        }    
    }

    for (int i = 0; i < len_s; i++)
    {
        if (smaller[i] > smax && smaller[i] != -1)
        {
            smax = smaller[i];
        }
    }

    if (abs(current - gmin) < abs(current - smax) && gmin != -1)
    {
        return gmin;
    } 
    else if (abs(current - smax) < abs(current - gmin) && smax != -1)
    {
        return smax;
    }

    return (gmin == -1)? smax:gmin;
}
