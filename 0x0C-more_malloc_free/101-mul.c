#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_digits(char *num);
void multiply(char *num1, char *num2, int len1, int len2);

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: an array of pointers to the arguments
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 3 || check_digits(argv[1]) || check_digits(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}
	multiply(argv[1], argv[2], strlen(argv[1]), strlen(argv[2]));
	return (0);
}

/**
 * check_digits - checks if string contains only digits
 * @num: the string to check
 *
 * Return: 0 if string contains only digits, 1 otherwise.
 */

int check_digits(char *num)
{
	while (*num)
	{
		if (*num < '0' || *num > '9')
			return (1);
		num++;
	}
	return (0);
}

/**
 * multiply - multiplies two positive numbers
 * @num1: the first number
 * @num2: the second number
 * @len1: the length of the first number
 * @len2: the length of the second number
 */

void multiply(char *num1, char *num2, int len1, int len2)
{
	int i, j, len, *result;
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
}
