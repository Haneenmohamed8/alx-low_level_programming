// _putchar.c
int _putchar(char c)
{
    return (write(1, &c, 1));
}

// _islower.c
int _islower(int c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

// _isalpha.c
int _isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

// _abs.c
int _abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

// _isupper.c
int _isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

// _isdigit.c
int _isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

// _strlen.c
int _strlen(char *s)
{
    int i = 0;
    while (*(s + i))
        i++;
    return (i);
}

// _puts.c
void _puts(char *s)
{
    int i = 0;
    while (*(s + i))
    {
        _putchar(*(s + i));
        i++;
    }
    _putchar('\n');
}

// _strcpy.c
char *_strcpy(char *dest, char *src)
{
    int i = 0;
    while (*(src + i))
    {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = '\0';
    return (dest);
}

// _atoi.c
int _atoi(char *s)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (*(s + i))
    {
        if (*(s + i) == '-')
            sign *= -1;
        if (*(s + i) >= '0' && *(s + i) <= '9')
        {
            result = result * 10 + (*(s + i) - '0');
            if (*(s + i + 1) < '0' || *(s + i + 1) > '9')
                break;
        }
        i++;
    }

    return (result * sign);
}

// _strcat.c
char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    while (*(dest + i))
        i++;
    while (*(src + j))
    {
        *(dest + i) = *(src + j);
        i++;
        j++;
    }
    *(dest + i) = '\0';
    return (dest);
}
