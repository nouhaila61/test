#include "shell.h"

int main(void)
{
    signal(SIGINT, controlC);
    prompt();
    return 0;
}
