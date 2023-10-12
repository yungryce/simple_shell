#include "main.h"


/**
 * init_buffer - Initialize the buffer for reading input.
 * @lineptr: Pointer to the buffer (may be NULL).
 * @n: Pointer to the buffer size.
 *
 * Return: status
*/
ssize_t init_buffer(char **lineptr, size_t *n)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUF_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	return (0);
}


/**
 * resize_buffer - Resize the buffer if it becomes too small.
 *
 * @lineptr: Pointer to the buffer.
 * @n: Pointer to the buffer size.
 * @new_size: The required new size for the buffer.
 *
 * Return: 0 on success, -1 on failure.
 */
ssize_t resize_buffer(char **lineptr, size_t *n, size_t new_size)
{
	char *new_ptr;

	if (new_size > *n)
	{
		new_ptr = _realloc(*lineptr, *n, new_size);
		if (new_ptr == NULL)
		{
			free(*lineptr);
			*lineptr = NULL;
			return (-1);
		}
		*lineptr = new_ptr;
		*n = new_size;
	}
	return (0);
}


/**
 * process_input - Process the input and look for a newline character.
 *
 * @buf: The buffer containing the input data.
 * @pos: The current position in the buffer.
 * @bytes_read: The number of bytes read in the current read operation.
 *
 * Return: The position of the newline character if found, or -1 if not found.
 */
ssize_t process_input(char *buf, size_t pos, ssize_t bytes_read)
{
	ssize_t i;

	for (i = 0; i < bytes_read; i++)
	{
		if (buf[pos - bytes_read + i] == '\n')
			return (pos);
	}
	return (-1);
}



/**
 * _getline - Read a line of input from a file descriptor.
 *
 * @lineptr: Pointer to the buffer where the line is stored.
 * @n: Pointer to the buffer size.
 * @fd: The file descriptor to read from.
 *
 * Return: The number of characters read, or -1 on error.
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t bytes_read, result;
	size_t pos = 0;
	char *buf;

	if (init_buffer(lineptr, n) < 0)
		return (-1);

	buf = *lineptr;
	while (1)
	{
		if (pos >= *n - 1)
		{
			if (resize_buffer(lineptr, n, *n * 2) < 0)
				return (-1);
			buf = *lineptr;
		}

		bytes_read = read(fd, buf + pos, *n - pos - 1);
		if (bytes_read <= 0)
			break;

		pos += bytes_read;

		result = process_input(buf, pos, bytes_read);
		if (result >= 0)
			return (result);
	}

	if (pos == 0)
		return (-1);

	return (pos);
}

