#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    int i, j, len1, len2, len;
    int *result;
    char *num1, *num2;

    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }

    num1 = argv[1];
    num2 = argv[2];
    len1 = strlen(num1);
    len2 = strlen(num2);

    for (i = 0; i < len1; i++)
    {
        if (num1[i] < '0' || num1[i] > '9')
        {
            printf("Error\n");
            exit(98);
        }
    }

    for (i = 0; i < len2; i++)
    {
        if (num2[i] < '0' || num2[i] > '9')
        {
            printf("Error\n");
            exit(98);
        }
    }

    len = len1 + len2;
    result = calloc(len, sizeof(int));

    if (result == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    i = 0;
    while (result[i] == 0 && i < len - 1)
        i++;

    while (i < len)
        printf("%d", result[i++]);

    printf("\n");
    free(result);

    return (0);
}
