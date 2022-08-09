#include "main.h"
/**
 * _strcpy - a function that coppies a string
 * @dest: a function parameter(destination)
 * @src: a function parameter(source)
 *
 * Return: character
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
