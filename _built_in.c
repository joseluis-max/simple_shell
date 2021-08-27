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
	int index = 0, status = 0;
	char *new_path = NULL, *PATH = NULL, *slash = NULL;
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
			free(slash);
		}
		if (stat(new_path, &st) == 0)
		{
			status = 1;
			_execute(new_path, filename, tokens, counter);
			free(new_path);
			break;
		}
		index++;
		free(new_path);
	}
	fd = access(tokens[0], F_OK);
	if (fd == 0)
		_check_path(tokens, filename, counter);
	if (status == 0 && fd == -1)
	{
		write(STDERR_FILENO, filename, _strlen(filename));
		write(STDERR_FILENO, ": ", 3);
		write(STDERR_FILENO, "1", 2), write(STDERR_FILENO, ": ", 3);
		write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
		write(STDERR_FILENO, ": ", 3), perror("");
	}
	free(t_path), free(PATH);
	return (status);
}
