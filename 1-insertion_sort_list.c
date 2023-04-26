#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *insertion, *temp;

    if (!list || !(*list) || !((*list)->next))
        return;

    curr = (*list)->next;

    while (curr)
    {
        insertion = curr->prev;
        temp = curr;

        while (insertion && insertion->n > temp->n)
        {
            if (insertion->prev)
                insertion->prev->next = temp;
            else
                *list = temp;

            if (temp->next)
                temp->next->prev = insertion;

            insertion->next = temp->next;
            temp->prev = insertion->prev;
            insertion->prev = temp;
            temp->next = insertion;

            insertion = temp->prev;
        }

        curr = curr->next;
    }
}

