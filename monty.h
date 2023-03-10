#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INSTRUCTIONS	\
	{		\
		{"push", _push},	\
		{"pall", _display},	\
		{"pint", pint},		\
		{"pop", pop},		\
		{"swap", swap},		\
		{"add", add},		\
		{"nop", nop},		\
		{"sub", sub},		\
		{"div", _div},		\
		{"mul", mul},		\
		{"mod", mod},		\
		{"pchar", pchar},	\
		{"pstr", pstr},		\
		{"rotl", rotl},		\
		{"rotr", rotr},		\
		{NULL, NULL}		\
	}

extern char *ch;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct mode - identify the data structure mode
 * @mod: holds the value 'stack' oe queues
 */
typedef struct mode
{
	int mod;
} mode;
mode status;


void add_node(stack_t **stack, int num);
void add_node_at_end(stack_t **stack, int num);


void _push(stack_t **stack, unsigned int line_number);
void _display(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);


void op_selector(stack_t **stack, char *token, unsigned int line_num);
int is_number(char *chr);
int check_n_element(stack_t **stack);
void free_list(stack_t *stack);
#endif
