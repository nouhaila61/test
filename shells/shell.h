#ifndef SHELL_H
#define SHELL_H

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int lookforslash(char *cmd);
int compareExit(char *s1, char *s2);
int compareEnv(char *s1, char *s2);
char **identify_string(char *parameter);
void execute_proc(char **argv);
void prompt(void);
void controlC(int sig);

#endif
