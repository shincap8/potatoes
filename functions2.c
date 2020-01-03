#include "library.h"
/**
 * ptr_bin - function that prints a variable type b
 * @list: list of functions
 * Return: the number of characters printed
 */
void is_add(sstack_t **head, unsigned int number)
{
	sstack_t *aux;
	int x = 0;

	number = number;
	if ((*head)->next != NULL)
	{
		x = (*head)->next->n + (*head)->n;
		aux = (*head)->next;
		aux->n = x;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * ptr_bin - function that prints a variable type b
 * @list: list of functions
 * Return: the number of characters printed
 */
void is_nop(sstack_t **head, unsigned int number)
{
	head = head;
	number = number;
}
