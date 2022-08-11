#include "main.h"
#include <string.h>

/**
 * _strcmp - a function that compares two strings
 * @s1: a functions variable that takes the first string
 * @s2: the second functions variable that takes a string
 *
 * Return: integer value
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
