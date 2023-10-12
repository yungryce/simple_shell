#include "main.h"

/**
 * is_whitespace - checks if a string consists of only whitespace
 * @str: input string to check
 *
 * Return: status
*/
int is_whitespace(const char *str)
{
	while (*str != '\0')
	{
		if (!_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * _isspace -  checks if character is a space character
 * @c: char to check
 *
 * Return: status
*/
int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\f' ||
	c == '\v'  || c == '\a' || c == '\n');
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
