#include "shell.h"
/**
 * _strdup - duplicate string
 *
 * @str: string for dup
 * Return: new string
 */
char *_strdup(char *str)
{
	unsigned int i = 0;
	unsigned int j;
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	s = malloc(sizeof(char) * i + 1);
	if (s == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		s[j] = str[j];
	}
	s[j] = '\0';
	return (s);
}
