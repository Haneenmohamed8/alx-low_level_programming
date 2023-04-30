#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the head of the linked list.
 * @idx: The index of the list where the new node should be added.
 * @n: The integer data of the new node.
 *
 * Return: If successful - The address of the new node.
 *         Otherwise - NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *prev_node, *current_node = *head;
	unsigned int i;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->n = n;

	if (!idx)
	{
		new_node->next = current_node;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; i < idx; i++)
	{
		if (!current_node)
		{
			free(new_node);
			return (NULL);
		}

		prev_node = current_node;
		current_node = current_node->next;
	}

	new_node->next = current_node;
	prev_node->next = new_node;

	return (new_node);
}

