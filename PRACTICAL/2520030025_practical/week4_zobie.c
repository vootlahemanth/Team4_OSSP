#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process\n");
        printf("Child PID: %d\n", getpid());
        printf("Child is terminating...\n");

        exit(0);
    }
    else
    {
        printf("Parent process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        printf("Parent is sleeping...\n");

        sleep(30);

        printf("Parent completed.\n");
    }

    return 0;
}
