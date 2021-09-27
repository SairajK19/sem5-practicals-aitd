#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("\n Child Process.");
        printf("\n Child Process id %d.", getpid());
        printf("\n It's parent process ID is %d.", getppid());
        sleep(5);
        printf("\n Child process after sleep for 5 seconds.");
        printf("\n Child process ID is %d.", getpid());
        printf("\n It's parent process ID is %d.", getppid());
    }
    else
    {
        printf("\n\n Parent Process.");
        sleep(10);
        printf("\n Child process ID is %d.", getpid());
        printf("\n It's parent process ID is %d.", getppid());
        printf("\n Parent terminates.\n\n");
    }
    return 0;
}