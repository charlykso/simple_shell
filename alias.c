#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void free_alias_list(alias_t *h);
list_t *add_node_end(list_t **h, char *dir);
void free_list(list_t *h);

/**
* add_node_end - Adds a node to the end of a list_t.
* @h: head of the list_t
* @d: The directory for the new node to contain.
* Return: If an error occurs - NULL.
*         else new node.
*/

list_t *add_node_end(list_t **h, char *dir)
{
list_t *new_node = malloc(sizeof(list_t));
list_t *last;

if (!new_node)
return (NULL);

new_node->dir = dir;
new_node->next = NULL;

if (*h)
{
last = *h;
while (last->next != NULL)
last = last->next;
last->next = new_node;
}
else
*h = new_node;

return (new_node);
}

/**
 * free_alias_list - Frees alias_t.
 * @h: THe head alias_t list.
 */
 
void free_alias_list(alias_t *h)
{
alias_t *next;

while (h)
{
next = h->next;
free(h->name);
free(h->value);
free(h);
h = next;
}
}

/**
* free_list - Frees list_t.
* @h: The head list_t.
*/

void free_list(list_t *h)
{
list_t *next;

while (h)
{
next = h->next;
free(h->dir);
free(h);
h = next;
}
}
