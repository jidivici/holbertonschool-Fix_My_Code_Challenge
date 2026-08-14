#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	dlistint_t *previous;
	dlistint_t *next;
	unsigned int position;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	position = 0;
	while (position < index && current != NULL)
	{
		current = current->next;
		position++;
	}
	if (current == NULL)
		return (-1);

	previous = current->prev;
	next = current->next;
	if (previous != NULL)
		previous->next = next;
	else
		*head = next;
	if (next != NULL)
		next->prev = previous;

	free(current);
	return (1);
}
