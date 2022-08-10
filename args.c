#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * free_args - Frees up memory.
 * @args: char
 * @first: char
 */

void free_args(char **args, char **first)
{
	size_t i;
	i = 0;

	while (args[i] || args[i + 1])
	{
		free(args[i]);
		i++;
	}
	free(first);
}
