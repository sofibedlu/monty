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
