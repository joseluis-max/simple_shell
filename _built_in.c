#include "shell.h"
/**
 * _built_in - search and execute built in command
 * @tokens: array with buffer split
 * @filename: name of executable
 * @counter: counter commands enter
 * Return: s_exceve status
 */
int _built_in(char **tokens, char *filename, int counter)
{
	int index = 0, s_execve, status = 0;
	char *new_path, *PATH, *slash;
	char **t_path;
	struct stat st;
	int fd;

	PATH = _getenv("PATH");
	t_path = split_string(PATH, ":");
	while (t_path[index] != NULL)
	{
		if (stat(tokens[0], &st) == -1)
		{
			slash = _strcat(t_path[index], "/");
			new_path = _strcat(slash, tokens[0]);
		}
		if (stat(new_path, &st) == 0)
		{
			status = 1;
			s_execve = _execute(new_path, filename, tokens, counter);
			break;
		}
		index++;
		free(slash);
		free(new_path);
	}
	fd = access(tokens[0], F_OK);
	if (fd == 0)
		_check_path(tokens, filename, counter);
	if (status == 0 && fd == -1)
		_print_error(filename, tokens[0], counter);
	free(t_path);
	return (s_execve);
}
