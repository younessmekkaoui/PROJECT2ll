#include "lists.h"
#include <stdlib.h>
#include <string.h>

list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node;
    unsigned int len = 0;

    while (str[len])
        len++;

    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);

    /* Duplicate the string */
    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return (NULL);
    }

    new_node->len = len;
    new_node->next = *head;

    *head = new_node;

    return (new_node);
}