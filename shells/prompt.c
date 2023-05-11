#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void prompt(void)
{
    char *text = NULL;
    size_t bufsize = 0;
    ssize_t lengbuff;
    pid_t child_pid;
    int status;

    while (1)
    {
        write(1, "$ ", 2);
        lengbuff = getline(&text, &bufsize, stdin);
        if (lengbuff == -1)
            exit(98);
        if (compareExit(text, "exit") == 0)
            exit(0);
        if (compareEnv(text, "env") == 0)
        {
            char **environ = __environ;
            while (*environ)
            {
                printf("%s\n", *environ);
                environ++;
            }
        }
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error");
            exit(1);
        }
        if (child_pid == 0)
        {
            identify_string(text);
            exit(EXIT_SUCCESS);
        }
        else
        {
            wait(&status);
        }
    }
}
