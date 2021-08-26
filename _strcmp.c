#include "shell.h"
/**
 * _strcmp - compare two string
 * @s1: string
 * @s2: string
 * Return: 0 equal string, positive number or negative number.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		if (s1[i] < s2[i])
		{
			return (-1 * (s2[i] - s1[i]));
		}
		i++;
	}
	return (0);
}
