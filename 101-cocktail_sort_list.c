// sort.h header file included to declare the listint_t type and print_list function
#include "sort.h"

/**
 * move_left - swaps two adjacent nodes of a doubly linked list
 *
 * @curr: current node
 * @prev: previous node
 * @head: head of the doubly linked list
 */
void move_left(listint_t *curr, listint_t *prev, listint_t **head);

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order using the
 *                      cocktail sort algorithm
 *
 * @list: pointer to the head node of the doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *cur;
    listint_t *max = NULL;
    listint_t *min = NULL;

    // check for empty list or single node
    if (!list || !(*list) || (*list)->next == NULL)
        return;

    cur = *list;
    do {
        // bubble sort forward until the last sorted element is reached
        while (cur->next)
        {
            if (cur->n > cur->next->n)
                move_left(cur->next, cur, list);
            else
                cur = cur->next;
        }
        max = cur;

        // bubble sort backward until the first sorted element is reached
        while (cur->prev != min)
        {
            if (cur->n < cur->prev->n)
                move_left(cur, cur->prev, list);
            else
                cur = cur->prev;
        }
        min = cur;
    } while (min != max);
}

/**
 * move_left - swaps two adjacent nodes of a doubly linked list
 *
 * @curr: current node
 * @prev: previous node
 * @head: head of the doubly linked list
 */
void move_left(listint_t *curr, listint_t *prev, listint_t **head)
{
    listint_t *swap1 = curr->next;
    listint_t *swap2 = prev->prev;

    // update the nodes adjacent to the swapped nodes
    if (swap1 != NULL)
        swap1->prev = prev;
    if (swap2 != NULL)
        swap2->next = curr;

    // swap the nodes
    curr->prev = swap2;
    prev->next = swap1;
    curr->next = prev;
    prev->prev = curr;

    // update the head node if necessary
    if (*head == prev)
        *head = curr;

    // print the sorted list after each swap
    print_list(*head);
}

