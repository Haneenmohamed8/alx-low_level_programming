#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 *
 * @head: Double pointer to the beginning of the list.
 *
 * Return: void.
 */

void free_listint2(listint_t **head)
{
	listint_t *current, *next;

	if (head == NULL)
		return;

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}
