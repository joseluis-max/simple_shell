#include "shell.h"
#include <stdio.h>


int main(void) {

	char *buffer;
	size_t b_size;
	ssize_t len;
	const char *del = " \t\r\n\a";
	char **tokens;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 3);
		len = getline(&buffer, &b_size, stdin);
		if (len != -1)
		{
			tokens = split_string(buffer, del);
			status = _execute_nb(tokens);
			if (status == 0)
				_execute(tokens);
		}
		else if (len == EOF)
		{
			free(buffer);
			if (isatty(STDIN_FILENO) != 0)
				write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		else
		{
			perror("Error: ");
			exit(98);
		}
	}
	return (0);
} 