#include "monty.h"

/**
 * push - Pushes an element to the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the file being processed.
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	stack_t *newNode = NULL;
	int i = 0, n;

	arg = strtok(NULL, " \t\n");
	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*arg == '-')
		i = 1;
	for (; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(arg);
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
