#include "main.h"
#include <stdio.h>


/**
 * is_palindrome - checks if a string is a palindrome
 *
 * @s: the string to check
 *
 * Return: 1 if @s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = 0;

    /* Get the length of the string */
	while (s[len])
		len++;

    /* Call the recursive function to check if it's a palindrome */
	return is_palindrome_helper(s, 0, len - 1);
}

/**
 * is_palindrome_helper - recursive helper function to check if a string is a palindrome
 *
 * @s: the string to check
 * @start: the starting index to compare
 * @end: the ending index to compare
 *
 * Return: 1 if @s is a palindrome, 0 otherwise
 */
int is_palindrome_helper(char *s, int start, int end)
{
    /* Base case: if start and end have met or crossed, the string is a palindrome */
	if (start >= end)
		return 1;

    /* If the characters at start and end are not equal, the string is not a palindrome */
	if (s[start] != s[end])
		return 0;

    /* Recursively check the rest of the string */
	return is_palindrome_helper(s, start + 1, end - 1);
}
