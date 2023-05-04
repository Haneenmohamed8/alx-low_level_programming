#include "main.h"
#include <stdio.h>

/**
 * find_sqrt - finds the square root recursively
 * @n: number to find the square root of
 * @sqrt: current square root candidate
 *
 * Return: square root of n or -1 if n doesn't have a natural square root
 */
int find_sqrt(int n, int sqrt)
{
	if (sqrt * sqrt > n)
		return (-1);
	if (sqrt * sqrt == n)
		return (sqrt);

	return (find_sqrt(n, sqrt + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Return: square root of n or -1 if n doesn't have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (find_sqrt(n, 0));
}
