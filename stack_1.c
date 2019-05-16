#include "monty.h"
/**
 * add_dnodeint - a function adds new node from the head of linked list
 * @head: double pointer of the head
 * @n: integer
 *
 * Return: return new node address on success, NULL if fail
 */

stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head)
		(*head)->prev = new;
	new->next = *head;
	new->prev = NULL;
	*head = new;
	return (new);
}

/**
 * push_op - a function pushes value to doubly linked list
 * @h: point to head
 * @l: line
 * Return: return NULL on success, EXIT_FAILURE on fail
 */

char *push_op(stack_t **h, unsigned int l)
{
	char *token;
	int i, j;

	strtok(global_line, " ");
	token = strtok(NULL, " ");
	if (!token)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	while (token[j] != '\0')
	{
		if (token[j] < '0' || token[j] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", l);
			if (*h)
				free_dlistint(*h);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	i = _atoi(token);
	add_dnodeint(h, i);
	return (NULL);
}

/**
 * pall_op - a function prints a value in doubly linked list
 * @h: point to head
 * @l: line
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *pall_op(stack_t **h, __attribute__((unused)) unsigned int l)
{
	stack_t *current;

	current = *h;
	if (current == NULL)
		return (NULL);
	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	return (NULL);
}

/**
 * pint_op - a function prints the value at the top of stack
 * @h: point to head
 * @l: line
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *pint_op(stack_t **h, unsigned int l)
{
	stack_t *current;

	current = *h;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", current->n);
	return (NULL);
}

/**
 * pop_op - a function pops the value at the top of stack
 * @h: point to head
 * @l: line
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *pop_op(stack_t **h, unsigned int l)
{
	stack_t *current;

	current = *h;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", l);
		exit(EXIT_FAILURE);
	}
	*h = current->next;
	if (*h)
		current->next->prev = NULL;
	free(current);
	return (NULL);
}
