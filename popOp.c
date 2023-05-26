#include "monty.h"

/**
 * popOp - Removes the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the file.
 */

void popOp(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
