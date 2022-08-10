#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void env_free(void);
char **_getenv(const char *var);

/**
 * env_free - Frees the the environ.
 */

void env_free(void)
{
	int i;
  
  i = 0;
	while (environ[i])
  {
		free(environ[i]);
    i++;
  }
	free(environ);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: char
 * Return: environ does not exist - NULL.
 *         else environ.
 */
char **_getenv(const char *var)
{
	int i, len;

	len = _strlen(var);
	
	i = 0;
	while (environ[i])
	{
		if (_strncmp(var, environ[i], len) == 0)
			return (&environ[i]);
	}

	return (NULL);
}
