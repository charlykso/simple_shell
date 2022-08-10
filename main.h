#ifndef _MAIN_
#define _MAIN_

extern char **environ;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */

typedef struct list_s
{
  char *dir;
  struct list_s *next;
} list_t;

/**
 * struct alias_s - A new struct for aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */

typedef struct alias_s
{
  char *name;
  char *value;
  struct alias_s *next;
} alias_t;


alias_t *aliases;

int tokenize(char *s);
void env_free(void);
void free_args(char **args, char **first);
char *find_location(char *com);
list_t *find_path_dir(char *path);
char *fill_path_dir(char *path);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
