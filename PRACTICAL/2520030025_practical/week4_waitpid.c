#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int i;
    pid_t pid;
    pid_t children[3];

    printf("Parent PID: %d\n", getpid());

    for (i = 0; i < 3; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            perror("fork failed");
            return 1;
        }

        if (pid == 0)
        {
            printf("Child %d started. PID = %d\n", i + 1, getpid());

            sleep((i + 1) * 2);

            printf("Child %d completed. PID = %d\n", i + 1, getpid());

            exit(10 + i);
        }

        children[i] = pid;
    }

    for (i = 0; i < 3; i++)
    {
        int status;

        waitpid(children[i], &status, 0);

        if (WIFEXITED(status))
        {
            printf("Child PID %d completed with status %d\n",
                   children[i],
                   WEXITSTATUS(status));
        }
    }

    printf("Parent process completed.\n");

    return 0;
}
