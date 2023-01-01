#include "monty.h"

/**
 * _push - pushes element to the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int num;

	/*(void)line_number;*/
	if ((ch == NULL) || (is_number(ch) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(ch);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new->n = num;
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->n = num;
		new->next = *stack;
		new->prev = NULL;
		(*stack)->prev = new;
		*stack = new;
	}
}
/**
 * _display - display elements in the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void _display(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - printd the value at the top of the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the top element of the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack == NULL)
		return;
	(*stack)->prev = NULL;
}
/**
 * is_number - check the input whether its integer or not
 * @chr: argument to the instruction to be checked
 * Return: 0 if not number 1 if its number
 */
int is_number(char *chr)
{
	int i = 0;

	if (chr == NULL)
		return (0);
	while (chr[i] != '\0')
	{
		if (chr[i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (chr[i] > 57 || chr[i] < 48)
			return (0);
		i++;
	}
	return (1);
}
