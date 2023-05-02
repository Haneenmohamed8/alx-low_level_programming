#include "variadic_functions.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_c - prints a character
 * @args: argument list containing the character to print
 */
void print_c(va_list args)
{
	char c = va_arg(args, int);

	printf("%c", c);
}

/**
 * print_i - prints an integer
 * @args: argument list containing the integer to print
 */
void print_i(va_list args)
{
	int i = va_arg(args, int);

	printf("%d", i);
}

/**
 * print_f - prints a float
 * @args: argument list containing the float to print
 */
void print_f(va_list args)
{
	float f = va_arg(args, double);

	printf("%f", f);
}

/**
 * print_s - prints a string
 * @args: argument list containing the string to print
 */
void print_s(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
		printf("(nil)");
	else
		printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	print_fmt_t formats[] = {
		{"c", print_c},
		{"i", print_i},
		{"f", print_f},
		{"s", print_s},
		{NULL, NULL}
	};
	va_list args;
	int i = 0, j = 0;
	char *separator = "";

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (formats[j].fmt)
		{
			if (*(formats[j].fmt) == format[i])
			{
				printf("%s", separator);
				formats[j].fn(args);
				separator = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	va_end(args);
	printf("\n");
}
