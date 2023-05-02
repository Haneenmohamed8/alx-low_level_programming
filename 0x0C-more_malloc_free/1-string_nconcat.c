#include "main.h"

/**
 * string_nconcat - concatenates two strings.
 * @s1: first string to concatenate.
 * @s2: second string to concatenate.
 * @n: number of bytes of s2 to concatenate.
 *
 * Return: pointer to newly allocated space containing the concatenated string.
 *         NULL if memory allocation fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *concat;

	if (s1 != NULL)
	{
		for (len1 = 0; s1[len1]; len1++)
			;
	}
	if (s2 != NULL)
	{
		for (len2 = 0; s2[len2]; len2++)
			;
		if (n >= len2)
			n = len2;
	}

	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];

	concat[i + j] = '\0';

	return (concat);
}
