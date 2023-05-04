#include "main.h"
#include <stdio.h>

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to calculate the square root of
 *
 * Return: the square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	return (sqrt_recursion_helper(n, 1, n));
}

/**
 * sqrt_recursion_helper - recursively calculates the square root of n
 * @n: the number to calculate the square root of
 * @low: the lowest possible value of the square root
 * @high: the highest possible value of the square root
 *
 * Return: the square root of n, or -1 if n does not have a natural square root
 */
int sqrt_recursion_helper(int n, int low, int high)
{
	int mid;

	if (low > high)
		return (-1);

	mid = (low + high) / 2;

	if (mid * mid == n)
		return (mid);

	if (mid * mid > n)
		return (sqrt_recursion_helper(n, low, mid - 1));

	return (sqrt_recursion_helper(n, mid + 1, high));
}
