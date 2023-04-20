#include "function_pointers.h"

/**
 *array_iterator - a function given as a parameter on each element of an array.
 * @array: array to execute func on
 * @size: is the size of the array
 * @action:  is a pointer to the function you need to use
 *
 * Return: Nothing.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t n;

	if (array && action)
	{
		n = 0;
		while (n < size)
		{
			action(array[n]);
			n++;
		}
	}
}
