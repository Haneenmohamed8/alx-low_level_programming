#include "function_pointers.h"

/**
 * print_name - a function that prints a name.
 * @name: the name given
 * @f: function of name
 *
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (f != NULL && name != NULL)

		f(name);
}
