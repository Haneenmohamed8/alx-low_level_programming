#include "main.h"

/**
 * *_memset - fills the first @n bytes of the memory area pointed to by @s with the constant byte @b
 * @s: pointer to put the constant
 * @b: constant
 * @n: max bytes to use
 *
 * Return: s
 */

char *_memset(char *s, char b, unsigned int n)
{
	for (unsigned int i = 0 ; i < n ; i++)
	{
		s[i] = b;
	}
	return (s);
}
