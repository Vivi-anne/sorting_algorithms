#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
    // Declare pointers to traverse the list
    listint_t *curr = NULL;
    listint_t *insertion = NULL;

    // Check for NULL or empty list
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    // Start sorting from the second node
    curr = (*list)->next;
    insertion = curr->prev;
    while (curr != NULL)
    {
        // Store the previous node of the current node
        insertion = curr->prev;
        
        // Move current node to its correct position
        while (insertion != NULL && insertion->n > curr->n)
        {
            // Swap current node and the previous node
            move_left(curr, insertion, list);
            insertion = curr->prev;
        }
        
        // Move to the next node
        curr = curr->next;
    }
}

/**
 * move_left - swaps two adjacent nodes in the doubly linked list
 * @curr: current node to be moved to the left of insertion
 * @insertion: insertion pointer
 * @head: pointer to the head of the doubly linked list
 */
void move_left(listint_t *curr, listint_t *insertion, listint_t **head)
{
    // Store nodes that need to be swapped
    listint_t *swap1 = curr->next;
    listint_t *swap2 = insertion->prev;

    // Update the next and previous nodes of the swapped nodes
    if (swap1 != NULL)
        swap1->prev = insertion;
    if (swap2 != NULL)
        swap2->next = curr;
    curr->prev = swap2;
    insertion->next = swap1;
    curr->next = insertion;
    insertion->prev = curr;
    
    // Update the head of the list if necessary
    if (*head == insertion)
        *head = curr;
    
    // Print the current state of the list
    print_list(*head);
}

