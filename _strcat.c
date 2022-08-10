#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);

/**
* _strcat - Concantenates two strings.
* @dest: Pointer to destination string.
* @src: Pointer to source string.
*
* Return: Pointer to destination string.
*/
char *_strcat(char *dest, const char *src)
{
char *destTemp;
const char *srcTemp;

destTemp = dest;
srcTemp =  src;

while (*destTemp != '\0')
destTemp++;

while (*srcTemp != '\0')
*destTemp++ = *srcTemp++;
*destTemp = '\0';
return (dest);
}

/**
* _strncat - Concantenates two strings where n number
*            of bytes are copied from source.
* @dest: Pointer to destination string.
* @src: Pointer to source string.
* @n: n bytes to copy from src.
*
* Return: Pointer to destination string.
*/
char *_strncat(char *dest, const char *src, size_t n)
{
size_t dest_len = _strlen(dest);
size_t i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[dest_len + i] = src[i];
dest[dest_len + i] = '\0';

return (dest);
}
