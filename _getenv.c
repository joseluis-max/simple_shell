#include "shell.h"
/**
 * _getenv - to get a var env
 * @var_env: name of var env
 * Return: value of va_env
 */
char *_getenv(char *var_env)
{
	int i = 0;
	char *copy;
	char *env, *rel, *r_copy;

	while (environ[i] != NULL)
	{       copy = _strdup(environ[i]);
		env = strtok(copy, "=");
		if (_strcmp(env, var_env) == 0)
		{
			rel = strtok(NULL, "=");
			r_copy = _strdup(rel);
			free(env);
			break;
		}
		i++;
		free(copy);
	}
	return (r_copy);
}
