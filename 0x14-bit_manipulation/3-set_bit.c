#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 *
 * @n: A pointer to an unsigned long integer.
 * @index: The index of the bit to set.
 *
 * Return: 1 on success, or -1 on failure.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8) - 1)
		return (-1);

	*n = *n | (1 << index);

	return (1);
}
