#include "monty.h"

/**
 * add_node - add node at the beggning of the list
 * @stack: top of stack pointer
 * @num: integer(data)
 */
void add_node(stack_t **stack, int num)
{
	stack_t *new;

	new  = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		new->next = NULL;
		*stack = new;
	}
}

/**
 * add_node_at_end - add new node at the end of the list
 * @stack: front of queue
 * @num: integer(data)
 */
void add_node_at_end(stack_t **stack, int num)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	new->n = num;
	new->next = NULL;
	if (temp == NULL)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}
