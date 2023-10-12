#include "main.h"



/**
* _puts - Prints a string to the standard output stream
* @str: The string to print
*
* Return: Void
*/
void _puts(char *str)
{
	size_t len;

	len = _strlen(str);

	if (write(STDOUT_FILENO, str, len) == -1)
		perror("error writing");

}


/**
* _pute - Prints a string to the standard error stream
* @str: The string to print
*
* Return: Void
*/
void _pute(char *str)
{
	size_t len;

	len = _strlen(str);

	if (write(STDERR_FILENO, str, len) == -1)
		perror("error writing");

}



/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void _putchar(char c)
{
		write(1, &c, 1);
}


/**
 * print_args - prints tokens.
 * @args: argument vector
 * Return: void
 */
void print_args(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		printf("args_print: %s\n", args[i]);
}


/**
 * print_list - function that prints all the elements of a listint_t list
 * @h: node pointer to a linked list
 * Return: number of nodes
 */

size_t print_list(list_t *h)
{
	list_t *head = h;
	size_t count = 0;

	while (head != NULL)
	{
		printf("%s\n", head->dir);
		head = head->next;
		count++;
	}

	return (count);
}

