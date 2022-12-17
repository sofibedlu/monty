#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *tp, *tp1;
	int n = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	if (n < 2 || !*stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tp1 = (*stack)->next;
	(*stack)->next = tp;
	tp->prev = (*stack);
	if (tp1 != NULL)
	{
		tp->next = tp1;
		tp->next->prev = tp;
	}
	else
		tp->next = NULL;
}
/**
 * add - adds the top two elemets of the stack
 * @stack: stack pointer
 * @line_number: line number of current instructions
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int n1 = 0, sum;

	while (temp != NULL)
	{
		temp = temp->next;
		n1++;
	}
	if (n1 < 2 || !*stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
/**
 * nop - this opcode doesn't do anything
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - subtract the top element of the stack from the second top
 * element of the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int n = 0, diff;

	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	if (n < 2 || !*stack)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	diff = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = diff;
}
