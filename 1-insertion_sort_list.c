#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr = (*list)->next;

    while (curr != NULL)
    {
        listint_t *insertion = curr->prev;
        while (insertion != NULL && insertion->n > curr->n)
        {
            /* Swap nodes */
            if (insertion->prev != NULL)
                insertion->prev->next = curr;
            if (curr->next != NULL)
                curr->next->prev = insertion;

            insertion->next = curr->next;
            curr->prev = insertion->prev;
            curr->next = insertion;
            insertion->prev = curr;

            /* Update head of list if necessary */
            if (*list == insertion)
                *list = curr;

            /* Print current state of list */
            print_list(*list);

            insertion = curr->prev;
        }

        curr = curr->next;
    }
}

