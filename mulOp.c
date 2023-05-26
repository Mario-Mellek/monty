#include "monty.h"

/**
 * mulOp - Multiplies the second top element of the stack by the top element.
 * @stack: Pointer to the top of the stack.
 * @line_number: The line number of the file being processed.
 */
void mulOp(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	popOp(stack, line_number);
}
