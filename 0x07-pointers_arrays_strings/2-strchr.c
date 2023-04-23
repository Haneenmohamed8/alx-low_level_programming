#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be searched
 * @c: The character to be located
 *
 * Return: If c is found - s.
 * If c is not found - NULL.
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
      return (s);
		else
      s++;
	}
	if (c == '\0')
		return (s);

	return (NULL);
}
