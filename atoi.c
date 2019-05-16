#include "monty.h"
/**
 * _atoi - a function that convert a string to an integer.
 * @s: a pointer that points to string
 *
 * Return: return a integer value
 */
int _atoi(char *s)
{
	int i = 0, int_num = 0, sign = 1, catch_it = 0;

	if (s == NULL)
		return (0);
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			catch_it = 1;
			int_num *= 10;
			int_num += (s[i] - '0');
		}
		else if (catch_it == 1)
			break;
		i++;
	}
	int_num *= sign;
	return (int_num);
}

/**
 * open_file - a function opens a file as iostream
 * @file_name: file name
 *
 * Return: return file descriptor
 */
FILE *open_file(char *file_name)
{
	FILE *fd1;

	fd1 = fopen(file_name, "r");
	if (!fd1)
	{
		fprintf(stderr, "Error: Cann't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	return (fd1);
}

/**
 * unknown_op - a function exits with failure status
 * @line_n: line number
 * @cmd: op instruction
 * @head: points to head
 * @fd: file descripter
 * Return: void
 */
void unknown_op(unsigned int line_n, char *cmd, stack_t *head, FILE *fd)
{
	fprintf(stderr, "L%d: unknown instr %s\n", line_n, cmd);
	if (head)
		free_dlistint(head);
	fclose(fd);
	exit(EXIT_FAILURE);
}
