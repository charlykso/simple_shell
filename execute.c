#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* execute - Executes a command in a child process.
* @args: An array of arguments.
* @first: A double pointer to the beginning of args.
*
* Return: If an error occurs - a corresponding error code.
*/

int execute(char **args, char **first)
{
    pid_t child_pid;
    int stat, flag, r;
    char *com = args[0];
  
    flag = 0;
    r = 0;

    if (com[0] != '/' && com[0] != '.')
    {
        flag = 1;
        com = get_location(com);
    }

    if (!com || (access(com, F_OK) == -1))
    {
        if (errno == EACCES)
            r = (create_error(args, 126));
        else
            r = (create_error(args, 127));
    }
    else
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            if (flag)
            free(com);
            perror("Error child:");
            return (1);
        }
    
        if (child_pid == 0)
        {
            execve(com, args, environ);
            if (errno == EACCES)
                r = (create_error(args, 126));
            env_free();
            free_args(args, first);
            free_alias_list(aliases);
            _exit(r);
        }
        else
        {
            wait(&stat);
            ret = WEXITSTATUS(stat);
        }
    }
    
    if (flag)
        free(com);
    return (r);
}
