#include "main.h"

/**
 * wildcmp_helper - helper function for wildcmp
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp_helper(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s2 == '*')
	{
		if (*s1 == '\0')
			return (wildcmp_helper(s1, s2 + 1));

		return (wildcmp_helper(s1 + 1, s2) || wildcmp_helper(s1, s2 + 1));
	}

	if (*s1 == *s2)
		return (wildcmp_helper(s1 + 1, s2 + 1));

	return (0);
}

/**
 * wildcmp - compares 2 strings and returns 1 if strings can be considered
 * identical, otherwise return 0.
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if the strings can be considered identical,otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*' && *(s2 + 1) == '\0')
		return (1);

	return (wildcmp_helper(s1, s2));
}
