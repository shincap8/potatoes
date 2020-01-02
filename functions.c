#include "library.h"
/**
 * ptr_bin - function that prints a variable type b
 * @list: list of functions
 * Return: the number of characters printed
 */
void is_push(sstack_t **head, unsigned int number)
{
	sstack_t *new;

	new = malloc(sizeof(sstack_t));
	if (new == NULL)
		exit (98);
	new->n = number;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	printf("%d", new->n);
	exit(98);
}
