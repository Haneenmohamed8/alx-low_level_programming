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
    if (*s1 == '\0' && *s2 == '\0') /* base case */
        return (1);

    if (*s2 == '*') /* if s2 contains '*', recursively check both sides of '*' */
    {
        if (*s1 == '\0') /* if s1 is empty, move s2 to the end of the string */
            return (wildcmp_helper(s1, s2 + 1));

        return (wildcmp_helper(s1 + 1, s2) || wildcmp_helper(s1, s2 + 1));
    }

    if (*s1 == *s2) /* if the characters match, continue checking the rest of the string */
        return (wildcmp_helper(s1 + 1, s2 + 1));

    return (0); /* if none of the conditions match, return 0 */
}

/**
 * wildcmp - compares two strings and returns 1 if the strings can be considered
 * identical, otherwise return 0.
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
    if (*s2 == '*' && *(s2 + 1) == '\0') /* if s2 only contains '*', it matches any string */
        return (1);

    return (wildcmp_helper(s1, s2)); /* call the helper function to compare the strings */
}
