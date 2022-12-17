#include "monty.h"
/**
 * free_list - freis the stack
 * @stack: stack pointer
 */
void free_list(stack_t *stack)
{
	stack_t *temp = stack;

	while (temp != NULL)
	{
		stack = stack->next;
		free(temp);
		temp = stack;
	}
}
