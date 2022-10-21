#include <stdio.h>

#define MAX 100

int full_counter = 0;

void wait(int *s)
{
    if (*s <= 0)
    {
        printf("\nBusy wait...\n");
    }
    *s -= 1;
}

void signal(int *s)
{
    *s += 1;
}

void producer(int *in, int *out, int *buffer, int *bs, int *mutex, int *empty, int *full)
{
    int nextProduced;

    wait(empty);
    wait(mutex);

    // if (((*in + 1)%*bs) == *out)
    if (full_counter == *bs)
    {
        printf("\nBuffer full\n", *full);
    }
    else
    {
        printf("\nItem to be produced: ");
        scanf("%d", &nextProduced);

        buffer[*in] = nextProduced;

        *in = (*in + 1) % *bs;

        full_counter++;

        signal(mutex);
        signal(full);
    }
}

void consumer(int *in, int *out, int *buffer, int *bs, int *mutex, int *empty, int *full)
{
    int nextConsumer;
    wait(full);
    wait(mutex);

    if (full_counter == 0)
    {
        printf("\nBuffer empty\n");
    }
    else
    {
        nextConsumer = buffer[*out];
        printf("\nItem consumed %d\n", nextConsumer);
        *out = (*out + 1) % *bs;

        full_counter--;

        signal(mutex);
        signal(empty);
    }
}

int main()
{
    int mutex = 1, empty, full = 0, in = 0, out = 0, bs, nextProduced, nextConsumer, input;

    printf("Buffer size: ");
    scanf("%d", &bs);

    empty = bs;

    int buffer[bs];

    while (1)
    {
        printf("\n1] Producer\n2] Consumer\n0] Exit\nInput: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            producer(&in, &out, buffer, &bs, &mutex, &empty, &full);
            break;
        case 2:
            consumer(&in, &out, buffer, &bs, &mutex, &empty, &full);
            break;
        case 0:
            return 0;
        }
    }

    printf("\n");
    return 0;
}
