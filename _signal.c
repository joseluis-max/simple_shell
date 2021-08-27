#include "shell.h"

void _handler(int s __attribute__((unused)))
{
        write(STDOUT_FILENO, "\n$ ", 3);
}
int _signal()
{
        if (signal(SIGINT, _handler) == SIG_ERR)
        {
                write(STDOUT_FILENO, "Can't catch signal", 19);
        }
        return (EXIT_SUCCESS);
}