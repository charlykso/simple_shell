#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char *fill_path_dir(char *path);
list_t *find_path_dir(char *path);

/**
* find_location - Locates a command in the PATH.
* @command: char
* Return: If an error occurs - NULL.
*         else the pathname of the command  id displayed.
*/

char *find_location(char *com)
{
char **path, *t;
list_t *dirs, *head;
struct stat st;

path = _getenv("PATH");
  
if (!path || !(*path))
return (NULL);

dirs = get_path_dir(*path + 5);
head = dirs;

while (dirs)
{
t = malloc(_strlen(dirs->dir) + _strlen(com) + 2);
if (!temp)
return (NULL);

_strcpy(t, dirs->dir);
_strcat(t, "/");
_strcat(t, com);

if (stat(t, &st) == 0)
{
free_list(head);
return (t);
}

dirs = dirs->next;
free(t);
}

free_list(head);

return (NULL);
}

/**
* fill_path_dir - Copies path
* @path: char
* Return: A copy of path
*/

char *fill_path_dir(char *path)
{
int i, len = 0;
char *c_path, *pwd;

pwd = *(_getenv("PWD")) + 4;
for (i = 0; path[i]; i++)
{
if (path[i] == ':')
{
if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
len += _strlen(pwd) + 1;
else
len++;
}
else
len++;
}
c_path = malloc(sizeof(char) * (len + 1));
if (!c_path)
return (NULL);
c_path[0] = '\0';
for (i = 0; path[i]; i++)
{
if (path[i] == ':')
{
if (i == 0)
{
_strcat(c_path, pwd);
_strcat(c_path, ":");
}
else if (path[i + 1] == ':' || path[i + 1] == '\0')
{
_strcat(c_path, ":");
_strcat(c_path, pwd);
}
else
_strcat(c_path, ":");
}
else
{
_strncat(c_path, &path[i], 1);
}
}
return (c_path);
}

/**
* find_path_dir - Tokenizes a colon-separated list of
*                directories into a list_s linked list.
* @path: The colon-separated list of directories.
*
* Return: A pointer to the initialized linked list.
*/
list_t *find_path_dir(char *path)
{
int i;
char **dirs, *c_path;
list_t *head = NULL;

c_path = fill_path_dir(path);
  
if (!c_path)
return (NULL);
dirs = strtok(c_path, ":");
free(c_path);
if (!dirs)
return (NULL);

i = 0;
while (dirs[i])
{
if (add_node_end(&head, dirs[index]) == NULL)
{
free_list(head);
free(dirs);
return (NULL);
}
i++;
}

free(dirs);

return (head);
}
