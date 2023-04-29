#include "sort.h"

/**
 * move_left - Moves a given node to the left of the insertion pointer
 *
 * @curr: The current node to be moved
 * @insertion: The insertion pointer
 * @head: The head of the list
 */
void move_left(listint_t *curr, listint_t *insertion, listint_t **head)
{
    listint_t *swap1 = curr->next;
    listint_t *swap2 = insertion->prev;

    if (swap1 != NULL)
        swap1->prev = insertion;
    if (swap2 != NULL)
        swap2->next = curr;
    curr->prev = swap2;
    insertion->next = swap1;
    curr->next = insertion;
    insertion->prev = curr;
    if (*head == insertion)
        *head = curr;

    /* Print the list after each swap */
    print_list(*head);
}

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: The head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr = NULL;
    listint_t *insertion = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    curr = (*list)->next;
    insertion = curr->prev;

    while (curr != NULL)
    {
        insertion = curr->prev;
        while (insertion != NULL && insertion->n > curr->n)
        {
            /* Move the current node to the left of the insertion pointer */
            move_left(curr, insertion, list);
            insertion = curr->prev;
        }
        curr = curr->next;
    }
}

