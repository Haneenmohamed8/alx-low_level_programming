/**
 * is_palindrome - checks if a string is a palindrome
 * @s: the string to check
 *
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
    int len = _strlen_recursion(s);
    int i;

    /* check for empty string */
    if (len == 0)
        return (1);

    /* check first and last characters */
    if (*s != s[len - 1])
        return (0);

    /* check substring in between first and last characters */
    s[len - 1] = '\0';
    i = is_palindrome(s + 1);
    s[len - 1] = s[0];

    return (i);
}
