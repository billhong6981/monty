#ifndef _MONTY_H
#define _MONTY_H
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        char *(*f)(stack_t **stack, unsigned int line_number, int i);
} instruction_t;

/* The following are prototypes */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream);
char *trun_space(char *str);
int _atoi(char *s);
int _strlen(char *s);
char *read_line(char *s, int *d);


#endif /* _MONTY_H */
