#include "monty.h"

/**
 * subOp - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the file being processed.
 */

void subOp(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	popOp(stack, line_number);
}
