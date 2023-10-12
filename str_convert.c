#include "main.h"


/**
 * _itoa - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *_itoa(int n)
{
	unsigned int num = n;
	char *str;
	int i, len = 1;
	int isNegative = 0;

	if (n < 0)
	{
		isNegative = 1;
		len++;
		num = -n;
	}
	while (num /= 10)
		len++;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	if (isNegative)
		str[0] = '-';

	for (i = len - 1; i >= 0; i--)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
	}

	str[len] = '\0';

	return (str);
}


/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int result = 0;
	int sign = 1;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;

	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			s++;
		}
		else
			return (0);

	}

	return (result * sign);
}


/**
 * _strspn - function that gets the length of a prefix substring.
 * @s: input string array
 * @accept: set of characters to search
 * Return: the number of bytes in the initial segment
 * of s which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j, flag;
	unsigned int count = 0;

	for (i = 0; s[i]; s++)
	{
		flag = 0;
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				count++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return (count);
		}
	}

	return (0);

}
