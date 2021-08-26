#include "shell.h"
/**
 * _strcat - concat two strings
 *
 * @dest: string for concat
 * @src: concat string value
 * Return: new string
 */
char *_strcat(char *dest, char *src)
{
	char *str;
	int i = 0;
	int j = 0;
	int k = 0;
	size_t s1;
	size_t s2;

	s1 = _strlen(dest);
	s2 = _strlen(src);

	str = malloc(1 + (s1 + s2) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		exit(98);
	}

	while (dest[i])
	{
		str[k] = dest[i];
		i++;
		k++;
	}
	while (src[j])
	{
		str[k] = src[j];
		j++;
		k++;
	}
	str[k] = '\0';

	return (str);
}