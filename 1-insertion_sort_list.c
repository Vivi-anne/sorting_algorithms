#include "sort.h"

/**
 * swap_nodes - Swap two adjusent nodes in list
 * @head: A pointer to the head of the double-linked list
 * @n1: A pointer to the first node to swap
 *  @n2: A pointer to the second node to swap
 */
void swap_nodes(listint_t **head, listint_t **n1, listint_t *n2);
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*head = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
