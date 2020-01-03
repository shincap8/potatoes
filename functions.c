#include "library.h"
/**
 * ptr_bin - function that prints a variable type b
 * @list: list of functions
 * Return: the number of characters printed
 */
void is_push(sstack_t **head, unsigned int number)
{
	sstack_t *new;

	if (number == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(sstack_t));
	if (new == NULL)
		exit (98);
	new->n = number;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
/**
 * ptr_bin - function that prints a variable type b
 * @list: list of functions
 * Return: the number of characters printed
 */
void is_pall(sstack_t **head, unsigned int number)
{
	sstack_t *tmp = *head;

	number = number;
	if (head == NULL || *head == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * ptr_bin - function that prints a variable type b
 * @list: list of functions
 * Return: the number of characters printed
 */
void is_pint(sstack_t **head, unsigned int number)
{
	number = number;
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * ptr_bin - function that prints a variable type b
 * @list: list of functions
 * Return: the number of characters printed
 */
void is_pop(sstack_t **head, unsigned int number)
{
	sstack_t *aux;

	number = number;
	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		aux = (*head)->next;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
	else
		free(*head), *head = NULL;
}
/**
 * ptr_bin - function that prints a variable type b
 * @list: list of functions
 * Return: the number of characters printed
 */
void is_swap(sstack_t **head, unsigned int number)
{
	int x = 0;

	number = number;
	if ((*head)->next != NULL)
	{
		x = (*head)->next->n;
		(*head)->next->n = (*head)->n;
		(*head)->n = x;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
