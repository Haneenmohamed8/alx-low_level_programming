#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string
 * @s: The string to find the length of
 *
 * Return: The length of the string
 */
int _strlen_recursion(char *s)
{
        if (*s == '\0')
                return (0);
        return (1 + _strlen_recursion(s + 1));
}


/**
 * _compare_chars - Compares two chars recursively
 * @start: The first char to compare
 * @end: The second char to compare
 *
 * Return: 1 if @start and @end are equal, 0 otherwise
 */
int _compare_chars(char *start, char *end)
{
        if (*start != *end)
                return (0);
        if (start >= end)
                return (1);
        return (_compare_chars(start + 1, end - 1));
}


/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if @s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
        int len = _strlen_recursion(s);

        if (len <= 1)
                return (1);
        return (_compare_chars(s, s + len - 1));
}
