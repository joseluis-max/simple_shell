#include "shell.h"
/**
 * _execute_nb - search and execute the command no built in
 * @tokens: array with buffer split
 * @counter: counter commands enter
 * Return: status
 */
int _execute_nb(char **tokens, int counter __attribute__((unused)))
{
	int index, cmp_s, status = 0;
	void (*noBuiltIn)();
	t_noBuiltIn commands_no_built_in[] = {
		{"env", _env},
		{"exit", _exit_},
		{".", _dot},
		{NULL}
	};

	index = 0;
	while (commands_no_built_in[index].command)
	{
		cmp_s = _strcmp(commands_no_built_in[index].command, tokens[0]);
		if (cmp_s == 0)
		{

			noBuiltIn = commands_no_built_in[index].command_function;
			noBuiltIn();
			status = 1;
			break;
		}
		index++;
	}
	return (status);
}
