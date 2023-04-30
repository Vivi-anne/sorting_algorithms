#include "sort.h"

/**
*len_list - Returns the length of a doubly linked list
*@head: Pointer to the Doubly Linked List
*
* Return: Length of Doubly Linked List
*/
int len_list(listint_t *head)
{
	int len = 0;

	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

/**
* swap_nodes - Swap two adjascent nodes in list
* @head: A pointer to the head of the double-linked list
* @node1: A pointer to the first node to swap
* @node2: A pointer to the second node to swap
*/
void swap_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
* insertion_sort_list - sorts a doubly linked list
* @list: A pointer to the head of doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b, *tmp;

	if (list == NULL || *list == NULL || len_list(*list) < 2)
		return;

	for (a = (*list)->next; a != NULL; a = tmp)
	{
		tmp = a->next;
		b = a->prev;
		while (b != NULL && b->n > a->n)
		{
			swap_nodes(list, &b, a);
			print_list((const listint_t *)*list);
		}
	}
}
