#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *node = head;
	const size_t table_size = 1024;
	bool visited[table_size];
	size_t i;
	
	for (i = 0; i < table_size; i++)
		visited[i] = false;

	while (node != NULL) 
	{
		printf("[%p] %d\n", (void *)node, node->n);
		count++;

	/* Check if the next node has already been visited */
	if (node->next != NULL && visited[(size_t)node->next % table_size]) 
	{
		printf("-> [%p] %d\n", (void *)node->next, node->next->n);
		break;
	}

		visited[(size_t)node % table_size] = true;
		node = node->next;
	}

	    /* If we reached the end of the list, return the number of nodes */
	if (node == NULL)
		return (count);

	/* If we found a cycle, exit the program with status 98 */
	exit(98);
}
