#include "monty.h"

/**
 * _div - divides the second top element of the stack by the top element of
 * the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void _div(stack_t **stack, unsigned int line_number)
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
/**
 * mul - multiply the top two element on the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int n, result;

	n = check_n_element(stack);
	if (n < 2 || !*stack)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * mod - computes the rest of the division of the second top
 * element of the stack by top element of the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int n, result;

	n = check_n_element(stack);
	if (n < 2 || !*stack)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
/**
 * pchar - prints the char at the top of the stack
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
