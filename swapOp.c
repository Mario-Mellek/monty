#include "monty.h"

/**
 * swapOp - Swaps the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the file.
 */

void swapOp(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
