#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * op_sub - performs subtraction operation
 * @a: first operand
 * @b: second operand
 *
 * Return: result of the subtraction operation
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_add - performs addition operation
 * @a: first operand
 * @b: second operand
 *
 * Return: result of the addition operation
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_mul - performs multiplication operation
 * @a: first operand
 * @b: second operand
 *
 * Return: result of the multiplication operation
 */
int op_mul(int a, int b)
{
	return (a * b);
}


/**
 * op_mod - performs modulus operation
 * @a: first operand
 * @b: second operand
 *
 * Return: result of the modulus operation
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}

/**
 * op_div - performs division operation
 * @a: first operand
 * @b: second operand
 *
 * Return: result of the division operation
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}
