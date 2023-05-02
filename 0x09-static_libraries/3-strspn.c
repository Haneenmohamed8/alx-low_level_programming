#include "main.h"
/**
 * _strspn -  gets the length of a prefix substring
 * @s: pointer to string
 * @accept: bytes to search for
 * Return: numer of pointers
 */
unsigned int _strspn(char *s, char *accept)
{
	int i;
	int num;
	int j;

	i = 0;
	num = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == ',' && s[i+1] == ' ')
			break;
		while (accept[j])
		{
			if (s[i] == accept[j])
				num++;
		}
	}
	return (num);
}
