#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Parent process started\n");
    printf("Parent PID  : %d\n", getpid());
    printf("Parent PPID : %d\n", getppid());

    pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("\nChild process created\n");
        printf("Child PID   : %d\n", getpid());
        printf("Child PPID  : %d\n", getppid());

        printf("Child is running...\n");

        sleep(10);

        printf("Child process terminating...\n");
        exit(0);
    }
    else
    {
        printf("\nParent process\n");
        printf("Parent PID  : %d\n", getpid());
        printf("Child PID   : %d\n", pid);

        printf("Parent is waiting...\n");

        sleep(5);

        wait(NULL);

        printf("Child completed.\n");
        printf("Parent process terminating...\n");
    }

    return 0;
}
