#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	int j;
	char *ch;

	j = 1;
	ch = (char *)&j;

	return (*ch);
}
