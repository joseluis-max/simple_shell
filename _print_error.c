#include "shell.h"
/**
 * _integer_to_string - convert int to string
 * @n: int for convert
 * Return: string of int n
 */
char *_integer_to_string(int n)
{
	int div;
	unsigned int num;
	char *buffer;
	int digit  = 1;
	int i = 0;

	div = 1;
	num = n;
	while (num / div > 9)
	{
		div *= 10;
		digit++;
	}
	buffer = malloc(sizeof(char) * digit);
	while (div > 0)
	{
		buffer[i] = '0' + (num / div);
		num %= div;
		div /= 10;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
/**
 * _print_error - print error
 * @filename: name of executable
 * @command: command name
 * @counter: counter of commands
 */
void _print_error(char *filename, char *command, int counter)
{
	char *numberInString;

	numberInString = _integer_to_string(counter);
	write(STDERR_FILENO, filename, _strlen(filename));
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, numberInString, _strlen(numberInString));
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 3);
	perror("");
	free(numberInString);
}
