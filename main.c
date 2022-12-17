#include "monty.h"

char *ch;

/**
 * main - entry point to the program
 * @ac: number of argument
 * @av: array of argument
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	stack_t *stack = NULL;
	FILE *file;
	unsigned int line_num = 1;
	size_t n = 0;
	char *token, *buffer;

	buffer = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buffer, &n, file)) != -1)
	{
		if (*buffer == '\n')
		{
			line_num++;
			continue;
		}
		token = strtok(buffer, " \n\t");
		if (!token || *token == '#')
		{
			line_num++;
			continue;
		}
		ch = strtok(NULL, " \n\t");
		op_selector(&stack, token, line_num);
		line_num++;
	}
	free(buffer);
	free_list(stack);
	fclose(file);
	return (0);
}
/**
 * op_selector - match the given opcode instruction
 * @stack: stack pointer
 * @token: instruction to be checked
 * @line_num: line_num of the currect instruction
 */
void op_selector(stack_t **stack, char *token, unsigned int line_num)
{
	int i = 0;
	instruction_t op_code[] = {
		{"push", _push},
		{"pall", _display},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{NULL, NULL}
	};

	(void)line_num;
	while (op_code[i].opcode != NULL)
	{
		if (strcmp(op_code[i].opcode, token) == 0)
		{
			op_code[i].f(stack, line_num);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token);
	exit(EXIT_FAILURE);
}
