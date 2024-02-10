#include <stddef.h> /* Agregar esta línea para definir NULL */
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Pointer to the head pointer of the list
 * Return: 1 if the list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *next;
    listint_t *slow = *head;
    listint_t *fast = *head;
    int is_pal = 1;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    if (fast != NULL)
        slow = slow->next;

    while (prev != NULL && slow != NULL)
    {
        if (prev->n != slow->n)
        {
            is_pal = 0;
            break;
        }
        prev = prev->next;
        slow = slow->next;
    }

    return (is_pal);
}
