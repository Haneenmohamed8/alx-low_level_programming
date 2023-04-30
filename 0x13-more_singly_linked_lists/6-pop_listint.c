#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 *               and returns the head node’s data (n).
 * @head: double pointer to the head node of the list
 *
 * Return: the data of the deleted node, or 0 if the list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	tmp = *head;
	*head = (*head)->next;
	n = tmp->n;
	free(tmp);

	return (n);
}
