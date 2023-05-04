#include "main.h"
#include <stdio.h>

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (check(n, 2));
}

/**
 * check_prime - checks if a number is prime recursively
 * @n: the number to check
 * @div: the divisor to check n against
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int check(int n, int div)
{
	if (n == div)
		return (1);

	if (n % div == 0)
		return (0);

	return (check(n, div + 1));
}
