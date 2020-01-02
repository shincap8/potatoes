#include "library.h"
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
	stack_t *head;
	instruction_t opd[] = {
		{"push", is_push},
		{"pall", is_pall}
	};

	head = NULL;
	if (argc > 2)
		printf("error");
	read_file(argv[1], opd, &head);
	return (0);
}
/**
* read_file - this function read
*
* Return: Always 0 (Success)
*/
void read_file(char *file, instruction_t opd, sstack_t **head)
{
	int fd, reader = 1024, i = 0, j = 0;
	char buffer[1024], buffercito[1024];

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
				search_in_opd(buffercito, opd, head);
			buffercito[j] = buffer[i], i++, j++;
		}
	}
}
void search_in_opd(char *buffercito, instruction_t opd, sstack_t **head)
{
	int i = 0, t = 0, j = 0;
	unsigned int x;

	while (j < 2)
	{
		while (buffercito[i] != ' ')
		{
			if (buffercito[i] == opd[j].opcode[i])
				t++;
			i++;
		}
		if (i == t)
		{
			if (isdigit(buffercito[i + 1]) != 0)
			{
				x = atoi(buffercito[i + 1]);
				opd[j].f(head, x);
			}
		}
		j++, i = 0, t = 0;
	}
}
