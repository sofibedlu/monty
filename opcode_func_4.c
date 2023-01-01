#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: stack pointer
 * @line_number: line number of current instructions
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (temp == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->next = NULL;
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: stack pointer
 * @line_number: line number of current instruction
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (temp == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*stack = temp;
}
