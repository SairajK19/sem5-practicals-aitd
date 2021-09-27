#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;
    pid = fork();
    if (pid < 0)
    {
        printf("Cannot create the file.\n");
        exit(0);
    }

    if (pid == 0)
    {
        printf("Child Process\n");
        exit(0);
    }
    else
    {
        printf("Parent process\n");
    }
    return 0;
}