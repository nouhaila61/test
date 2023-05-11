#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t ppid;

        ppid = getppid();
	    printf("parent process ID: %u\n", ppid);

        return (0);
}

