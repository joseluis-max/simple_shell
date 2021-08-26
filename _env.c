#include "shell.h"

/**
 * _env - print a environment
 */
void _env(void)
{
	int i = 0;
	size_t size;

	while (environ[i] != NULL)
	{
		size = _strlen(environ[i]);
		size = size + 1;
		write(STDOUT_FILENO, environ[i], size);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
