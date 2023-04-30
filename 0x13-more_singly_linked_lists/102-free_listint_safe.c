#include "lists.h"
#include <stdlib.h>

#define TABLE_SIZE 1024

/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: Double pointer to the head of the list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *node, *tmp;
	listint_t *table[TABLE_SIZE] = {NULL};
	size_t index;

	if (h == NULL || *h == NULL)
		return (0);

	node = *h;
	while (node != NULL)
	{
		index = (size_t)node % TABLE_SIZE;
		if (table[index] == NULL)
		{
			table[index] = node;
			tmp = node;
			node = node->next;
			free(tmp);
			count++;
		}
		else if (table[index] == node)
		{
			*h = NULL;
			return (count);
		}
		else
		{
			tmp = node;
			node = node->next;
			free(tmp);
			count++;
		}
	}

	*h = NULL;
	return (count);
}
