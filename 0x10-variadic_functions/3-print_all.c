#include "variadic_functions.h"

/**
 * print_char - print a character
 * @arg: the argument to print
 */
void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_int - print an integer
 * @arg: the argument to print
 */
void print_int(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * print_float - print a float
 * @arg: the argument to print
 */
void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_string - print a string
 * @arg: the argument to print
 */
void print_string(va_list arg)
{
	char *str = va_arg(arg, char *);

	if (str == NULL)
	{
		printf("(nil)");
		return;
	}

	printf("%s", str);
}

/**
 * print_all - print anything
 * @format: a list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j;
	char *separator = "";
	print_fn print_fns[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;

		while (print_fns[j].fn != NULL)
		{
			if (format[i] == print_fns[j].format)
			{
				printf("%s", separator);
				print_fns[j].fn(args);
				separator = ", ";
				break;
			}

			j++;
		}

		i++;
	}

	printf("\n");

	va_end(args);
}
