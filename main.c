#include "shell.h"
/**
 * main - shell
 * @ac: counter arguments
 * @av: arguments array
 * Return: 1 | 0
 */
int main(int ac __attribute__((unused)), char *av[])
{

	char *buffer = NULL;
	size_t b_size;
	ssize_t len;
	const char *del = " \t\r\n\a";
	char **tokens;
	int status = 0, counter = 0;

	while (1)
	{
		counter++;
		if ((isatty(fileno(stdin))))
			write(STDOUT_FILENO, "$ ", 3);
		_signal();
		len = getline(&buffer, &b_size, stdin);
		if (len != -1)
		{
			if (buffer[0] == '\n')
			{
				write(STDOUT_FILENO, "", 1);
				continue;
			}
			tokens = split_string(buffer, del);
			status = _execute_nb(tokens, buffer);
			if (status == 0)
				status = _built_in(tokens, av[0], counter);
			free(tokens);
		}
		else if (len == EOF)
		{
			free(buffer);
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		else
			free(buffer);
	}
	return (0);
}
