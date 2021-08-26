#include "shell.h"
/**
 * _strlen - function the returns the length of s tring
 *
 * @s: char variable to find length
 * Return: length of a string
 */
size_t _strlen(char *s)
{
	size_t l;

	for (l = 0; s[l] != '\0'; l++)
		;
	return (l);
}