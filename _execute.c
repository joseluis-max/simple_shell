#include "shell.h"
/**
 * _execute - execute built in command
 * @new_path: complete path
 * @tokens: array with buffer split
 * @filename: name of executable
 * @counter: counter commands enter
 * Return: s_exceve status
 */
int _execute(char *new_path, char *filename, char **tokens, int counter)
{
	pid_t pid;
	int s_execve = 0, status_w;

	pid = fork();
	if (pid != -1)
	{
		if (pid == 0)
		{
			s_execve = execve(new_path, tokens, environ);
			if (s_execve == -1)
				_print_error(filename, tokens[0], counter);
		}
		wait(&status_w);
	}
	else
		perror("Error: ");
	return (s_execve);
}