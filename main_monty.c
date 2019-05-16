#include "monty.h"
/**
 * main - a function interpretes the Monty opcode
 * @argc: number of arguments
 * @argv: content of arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE if fail
 */
int main(int argc, char **argv)
{
	char *cmd, *line = NULL;
	FILE *fd;
	stack_t *head = NULL;
	size_t len;
	unsigned int line_n = 0;
	char *(*found_opcode)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monte file\n");
		exit(EXIT_FAILURE);
	}
	fd = open_file(argv[1]);
	while (1)
	{
		if ((_get_line(&line, &len, fd)) == -1)
		{
			if (line)
				free(line);
			break;
		}
		global_line = trun_space(line);
		++line_n;
		if (global_line == NULL)
			continue;
		cmd = read_line(global_line);
		free(line);
		found_opcode = get_opcode_fn(cmd);
		if (found_opcode != NULL)
			found_opcode(&head, line_n);
		else
		{
			fprintf(stderr, "L%d: unknown instr %s\n", line_n, cmd);
			if (head)
				free_dlistint(head);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
	}
	if (head)
		free_dlistint(head);
	fclose(fd);
	exit(EXIT_SUCCESS);
}
