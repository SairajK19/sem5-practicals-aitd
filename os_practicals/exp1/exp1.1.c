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
        printf("Child Process, pid : %d\n", pid);
        exit(0);
    }
    else
    {
        printf("Parent process, pid : %d\n", pid);
    }
    return 0;
}