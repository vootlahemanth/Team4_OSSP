#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int i;
    pid_t pid;

    printf("Parent PID: %d\n", getpid());

    for (i = 1; i <= 3; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            perror("fork failed");
            return 1;
        }

        if (pid == 0)
        {
            printf("Child %d started. PID = %d\n", i, getpid());

            sleep(i * 2);

            printf("Child %d completed. PID = %d\n", i, getpid());

            exit(0);
        }
    }

    for (i = 1; i <= 3; i++)
    {
        wait(NULL);
        printf("Parent collected a child.\n");
    }

    printf("All children completed.\n");

    return 0;
}
