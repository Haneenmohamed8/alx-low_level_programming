#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - searches for an integer
 * @array: pointer to the array to search
 * @size: number of elements in the array
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: the index of the first element for which cmp doesn't return 0,
 * or -1 if no such element is found or if size <= 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array == NULL || cmp == NULL)
		return (-1);

	for (int i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
