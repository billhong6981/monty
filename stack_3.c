#include "monty.h"
/**
 * sub_op - a function subtracts the top two Nodes value in the stack
 * @h: points to head
 * @l: line
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *sub_op(stack_t **h, unsigned int l, FILE *fd)
{
	size_t i;
	stack_t *current;

	current = *h;
	i = dlistint_len(h);
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", l);
		if (current)
			free_dlistint(current);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	current->next->n -= current->n;
	*h = current->next;
	current->next->prev = NULL;
	free(current);
	return (NULL);
}

/**
 * div_op - a function divides the top two Nodes value in the stack
 * @h: points to head
 * @l: line
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *div_op(stack_t **h, unsigned int l, FILE *fd)
{
	size_t i;
	stack_t *current;

	current = *h;
	i = dlistint_len(h);
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", l);
		if (current)
			free_dlistint(current);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l);
		if (current)
			free_dlistint(current);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	current->next->n /= current->n;
	*h = current->next;
	current->next->prev = NULL;
	free(current);
	return (NULL);
}

/**
 * mul_op - a function multiplies the top two Nodes value in the stack
 * @h: points to head
 * @l: line
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *mul_op(stack_t **h, unsigned int l, FILE *fd)
{
	size_t i;
	stack_t *current;

	current = *h;
	i = dlistint_len(h);
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", l);
		if (current)
			free_dlistint(current);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	current->next->n *= current->n;
	*h = current->next;
	current->next->prev = NULL;
	free(current);
	return (NULL);
}

/**
 * mod_op - a function gets the remainder from dividing the top two Nodes value
 * @h: points to head
 * @l: line
 * Return: return NULL on success, EXIT_FAILURE on fail
 */
char *mod_op(stack_t **h, unsigned int l, FILE *fd)
{
	size_t i;
	stack_t *current;

	current = *h;
	i = dlistint_len(h);
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", l);
		if (current)
			free_dlistint(current);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", l);
		if (current)
			free_dlistint(current);
		fclose(fd);
		exit(EXIT_FAILURE);
	}
	current->next->n %= current->n;
	*h = current->next;
	current->next->prev = NULL;
	free(current);
	return (NULL);
}
