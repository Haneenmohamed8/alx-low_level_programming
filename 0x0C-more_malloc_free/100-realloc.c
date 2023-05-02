#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated with a call to malloc.
 * @old_size: The size, in bytes, of the allocated space for ptr.
 * @new_size: The new size, in bytes, of the new memory block.
 *
 * Return: A pointer to the reallocated memory block.
 *         NULL, if new_size == 0 and ptr is not NULL.
 *         ptr, if new_size == old_size.
 *         NULL, if memory allocation fails.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *cur_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		return (new_ptr);
	}
	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	cur_ptr = ptr;
	for (i = 0; i < old_size && i < new_size; i++)
		new_ptr[i] = cur_ptr[i];
	free(ptr);
	return (new_ptr);
}
