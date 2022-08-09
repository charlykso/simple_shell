#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

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
