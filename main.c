#include "library.h"
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	sstack_t *head;
	instruction_t opd[] = {
		{"push", is_push},
		{"pall", is_pall},
		{"pint", is_pint},
		{"pop", is_pop},
		{"swap", is_swap},
		{"add", is_add},
		{"nop", is_nop}
	};

	head = NULL;
	if (argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_filex(argv[1], opd, &head);
	return (0);
}
/**
* read_file - this function read
*
* Return: Always 0 (Success)
*/
void read_filex(char *file, instruction_t *opd, sstack_t **head)
{
	int fd, reader = 1024, i = 0, j = 0;
	char buffer[1024], *buffercito;

	line_number = 0;
	buffercito = malloc(1024);
	if (buffercito == NULL)
		exit(98);
	fd = open(file, O_RDONLY, 0600);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file\n"), exit(98);
	while (reader == 1024)
	{
		reader = read(fd, buffer, 1024);
		if (reader == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file\n");
			exit(98);
		}
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				line_number++;
				search_in_opd(buffercito, opd, head), j = 0;
				free(buffercito);
				buffercito = malloc(1024);
				i++;
			}
			buffercito[j] = buffer[i], i++, j++;
		}
	}
}
void search_in_opd(char *buffercito, instruction_t *opd, sstack_t **head)
{
	int i = 0, t = 0, j = 0;
	unsigned int x = 0;

	while (j < 7)
	{
		i = 0, t = 0;
		while (buffercito[i] != ' ' && buffercito[i])
		{
			if (buffercito[i] == opd[j].opcode[i])
				t++;
			i++;
		}
		if (opd[j].opcode[i] != '\0')
			t = 0;
		if (i == t)
		{
			x = get_int(buffercito);
			opd[j].f(head, x);
			break;
		}
		j++;
	}
	if (i != t)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, buffercito);
		exit(EXIT_FAILURE);
	}
}
