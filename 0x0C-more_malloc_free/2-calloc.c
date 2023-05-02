#include "main.h"

/**
 * _calloc - Allocates memory for an array of nmemb elements of size bytes
 *           each and sets the memory to zero.
 * @nmemb: The number of elements to allocate memory for.
 * @size: The size of each element.
 *
 * Return: If memory allocation fails, returns NULL.
 *         Otherwise, returns a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		*((char *)ptr + i) = 0;

	return (ptr);
}
