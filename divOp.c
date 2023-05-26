#include "monty.h"

/**
 * divOp - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the file being processed.
 */

void divOp(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	popOp(stack, line_number);
}
