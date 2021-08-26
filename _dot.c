#include "shell.h"
/**
 * _dot - put "" in stdout
 */
void _dot(void)
{
        write(STDOUT_FILENO, "", 1);
}