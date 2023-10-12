#include "main.h"

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: char to test.
 * @delim: The delimiter string.
 *
 * Return: (1) if delim is true
 */

int is_delimiter(char c, char *delim)
{
	int i;

	for (i = 0; delim[i] != '\0'; i++)
	{
		if (c == delim[i])
			return (1);
	}
	return (0);
}

/**
 * token_delim_count - Counts the number of delimited
 *                words contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */
size_t token_delim_count(char *str, char *delim)
{
	size_t count = 0;

	while (*str != '\0')
	{
		if (!is_delimiter(*str, delim))
		{
			count++;
			while (*str != '\0' && !is_delimiter(*str, delim))
				str++;
		}

		str++;
	}

	return (count);
}


/**
 * token_count - argc
 * @tokens: pointer to input vector args.
 *
 * Return: count
 */

int token_count(char **tokens)
{
	int count = 0;

	while (tokens[count] != NULL)
		count++;

	return (count);
}


/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 */

void rev_string(char *s)
{
	int end, start;
	char d;

	for (end = 0; s[end] != '\0'; end++)
		;
	end--;
	for (start = 0; start < end; start++, end--)
	{
		d = s[start];
		s[start] = s[end];
		s[end] = d;
	}
}

