#include "main.h"


/**
 * add_node_end - add new nodes for splitted paths
 * @head: head of node pointer
 * @directory: splitted value to be put in a node
 * Return: new head of node
 */
list_t *add_node_end(list_t *head, char *directory)
{
	list_t *new_node = NULL;
	list_t *current = NULL;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->dir = _strdup(directory);
	new_node->next = NULL;

	if (!head)
		head = new_node;

	else
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}


	return (head);
}


/**
 * free_list - frees node list
 * @head: head of node list
 *
 * Return: void
*/
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->dir);
		head->dir = NULL;
		free(head);
		head = temp;
	}
	head = NULL;
}




