#include "monty.h"
/**
 * _get_line - gets a line form stdin
 * @lineptr: a pointer to the line
 * @n: the length of the string
 * @stream: the file that is being read from
 * Return: *n -1 if lineptr is NULL, or n = i
 */
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream)
{
	size_t maxchar = 1024, i = 0;
	int c;

	(*lineptr) = malloc(maxchar * sizeof(char));
	if ((*lineptr) == NULL)
		return (*n = -1);
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF)
		{
			free(*lineptr);
			return (*n = -1);
		}
		if ((i >= maxchar - 2) || c == '\n')
			break;
		(*lineptr)[i++] = c;
	}
	if (i >= maxchar - 2)
	{
		maxchar += maxchar;
		(*lineptr) = _realloc((*lineptr), i, maxchar);
		if ((*lineptr) == NULL)
			return (*n = -1);
	}
	else
	{
		(*lineptr)[i] = '\n';
		(*lineptr)[++i] = '\0';
	}
	return (*n = i);
}

/**
 * _realloc - a function that reallocates block of memory using malloc and free
 * @ptr: a pointer point to old block of memory
 * @old_size: old size of the block of memory
 * @new_size: new size of the block of memory
 *
 * Return: return a pointer point to new block of memory, or NULL if fail
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *block, *ptr1;

	if (new_size <= old_size)
		return (ptr);
	if (ptr == NULL)
	{
		block = malloc(new_size);
		return (block);
	}
	block = malloc(sizeof(*block) * new_size);
	if (block == NULL)
		return (NULL);
	ptr1 = ptr;
	for (i = 0; i < old_size; i++)
		block[i] = ptr1[i];
	free(ptr);
	return (block);
}

/**
 * trun_space - a function that deletes the leading space(se)
 * @str: a string
 * Return: return a string
 */
char *trun_space(char *str)
{
	char *str1;
	static char buffer[1000];
	int len;
	int flag = 0;

	str1 = &buffer[999];
	*str1 = '\0';
	len = strlen(str);
	while (len)
	{
		--len;
		if (str[len] != ' ' && str[len] != '\n' && flag == 0)
		{
			*(--str1) = str[len];
			flag = 1;
			continue;
		}
		if (str[len] == ' ' || str[len] == '\n')
			continue;
		if (str[len] != ' ' && str[len + 1] == ' ')
		{
			*(--str1) = ' ';
			*(--str1) = str[len];
		}
		else
		{
			*(--str1) = str[len];
		}
	}
	return ((flag == 0) ? (NULL) : (str1));
}
