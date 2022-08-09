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

int tokenize(char *s);
void env_free(void);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
