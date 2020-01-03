#include "library.h"
int get_int(char *buffer)
{
	int i = 0, j = 0, t = 0;

	while (buffer[i])
	{
		if (buffer[i] == ' ')
		{
			while (buffer[i] == ' ')
				i++;
			j = i;
			if (buffer[i] < 48 || buffer[i] > 57)
			{
				return (-1);
			}
			while (buffer[i] != ' ' && buffer[i])
			{
				if (buffer[i] >= 48 && buffer[i] <= 57)
					i = i;
				else
					t++;
				i++;
			}
			if (t == 0)
			{
				buffer = buffer + j;
				i = atoi(buffer);
				return (i);
			}
			if (t != 0)
			{
				return (-1);
			}
		}
		t = 0, i++;
	}
	return (-1);
}
