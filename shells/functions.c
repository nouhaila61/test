#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lookforslash(char *cmd)
{
	int counter = 0;

	while (cmd[counter])
	{
		if (cmd[0] == '/')
		{
			printf("%c\n", cmd[0]);
			return 1;
		}

		counter++;
	}
	return 0;
}

int compareExit(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 3)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

int compareEnv(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 2)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

char **identify_string(char *parameter)
{
	char **buf = malloc(1024 * sizeof(char *));
	char *split;
	int i = 0;
	char *delim = " \t\n";

	split = strtok(parameter, delim);

	while (split != NULL)
	{
		buf[i] = split;
		i++;
		split = strtok(NULL, delim);
	}
	buf[i] = NULL;
	execute_proc(buf);
	return buf;
}

void counterrolC(int sig)
{
	(void)sig;
	write(1, "\n$ ", 3);
}
