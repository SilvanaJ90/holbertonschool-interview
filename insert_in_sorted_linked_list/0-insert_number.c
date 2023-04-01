#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_node: check code
 * number: value
 * @head: value pointer
 * Return: list short - new_node or NULL if faile
 * */


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_number, *current;

	new_number= malloc(sizeof(listint_t));
	if (new_number == NULL)
		return (NULL);
	new_number->n = number;
	new_number->next = NULL;

	if (*head == NULL || number < (*head)->n)
	{
		new_number->next = *head;
		*head = new_number;
		return new_number;
	}

	current = *head;
	while(current->next != NULL && current->next->n < number)
		current = current->next;

	new_number->next = current->next;
	current->next = new_number;

	return new_number;
}
