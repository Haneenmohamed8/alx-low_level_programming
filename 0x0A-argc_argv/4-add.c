#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point of the program
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments passed to the program
 *
 * Return: 0 if successful, 1 if an error occurred
 */

int main(int argc, char *argv[])
{
	int sum = 0, i = 0;
	int j;

	if (argc == 1)
	{
		printf("%d\n", 0);
		return (0);
	}
	else
	{
		for (j = 1; j < argc; j++)
		{
			i = 0;
			while (argv[j][i])
			{
				if (!((argv[j][i] >= 48) && (argv[j][i] <= 57)))
				{
					printf("Error\n");
					return (1);
				}
				i++;
			}
		}
		for (j = 1; j < argc; j++)
		{
			sum = sum + atoi(argv[j]);
		}
	}
	printf("%d\n", sum);
	return (0);
}
