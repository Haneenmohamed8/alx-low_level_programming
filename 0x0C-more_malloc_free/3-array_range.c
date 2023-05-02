#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: minimum value of array (included)
 * @max: maximum value of array (included)
 *
 * Return: pointer to the newly created array
 *         or NULL if min > max or if malloc fails
 */
int *array_range(int min, int max)
{
        int *arr, i;

        if (min > max)
                return (NULL);

        arr = malloc(sizeof(int) * (max - min + 1));
        if (arr == NULL)
                return (NULL);

        for (i = 0; i <= max - min; i++)
                arr[i] = min + i;

        return (arr);
}
