#include "monty.h"

/**
 * div - divides the second top element of the stack by the top element of
 * the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void div(stack **stack, unsigned int line_number)
{
	int n, division;

	n = check_n_element(stack);
	if (n < 2 || !*stack)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	division = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = division;
}
