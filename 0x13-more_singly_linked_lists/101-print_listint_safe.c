#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the beginning of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current;
	const listint_t *array[1024];
	size_t i, size;

	size = 0;
	current = head;

	while (current != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (current == array[i])
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (size);
			}
		}

		array[size] = current;
		size++;

		printf("[%p] %d\n", (void *)current, current->n);

		current = current->next;
	}

	return (size);
}
