#include "main.h"
/**
 * _memcpy - copies memory area
 * @dest: pointer for destination
 * @src: pointersource
 * @n: number of bytes
 * Return: pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
