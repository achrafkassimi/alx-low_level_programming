#include "lists.h"

/**
 * add_nodeint - adds a no node at the beginning of a linked list
 * @hea: pointer to the first node in the list
 * @n: data to insert in that no node
 *
 * Return: pointer to the no node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **hea, const int n)
{
	listint_t *no;

	no = malloc(sizeof(listint_t));
	if (!no)
		return (NULL);

	no->n = n;
	no->next = *hea;
	*hea = no;

	return (no);
}
