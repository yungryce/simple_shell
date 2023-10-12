#include "main.h"


/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char *str, char *delim)
{
	static char *next_token;
	char *token_start;

	if (str != NULL)
		next_token = str;

	if (!next_token || *next_token == '\0')
		return (NULL);

	while (*next_token != '\0' && is_delimiter(*next_token, delim))
		next_token++;

	if (*next_token == '\0')
		return (NULL);

	token_start = next_token;

	while (*next_token != '\0' && !is_delimiter(*next_token, delim))
		next_token++;

	if (*next_token != '\0')
	{
		*next_token = '\0';
		next_token++;
	}

	return (token_start);
}

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}




/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @src: size, in bytes, of the allocated space of ptr.
 * @dest: new size, in bytes, of the new memory block.
 *
 * Return: new pointer to dest
 */
char **_reallocdp(char **ptr, size_t src, size_t dest)
{
	char **newptr = (char **)malloc(dest * sizeof(char *));
	size_t i;

	if (ptr == NULL)
		return (newptr); /* line 53 */

	if (ptr != NULL && dest == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < src; i++)
		newptr[i] = ptr[i]; /* line 66 */

	free(ptr);
	return (newptr);
}
