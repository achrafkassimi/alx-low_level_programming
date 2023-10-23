#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @k: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *k)
{
	size_t n1 = 0;

	for (; k; k = k->next)
	{
		printf("%d\n", k->n);
		n1++;
	}

	return (n1);
}
