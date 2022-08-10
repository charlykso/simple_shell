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

char *tokenize(char *s);
void env_free(void);
char **_getenv(const char *var);
void free_args(char **args, char **first);
void free_alias_list(alias_t *h);
list_t *add_node_end(list_t **h, char *dir);
void free_list(list_t *h);
char *find_location(char *com);
list_t *find_path_dir(char *path);
char *fill_path_dir(char *path);
int create_error(char **args, int err);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, const char *src, size_t n);
int _strlen(char *s);
int num_len(int num);
char *_itoa(int num);

#endif
