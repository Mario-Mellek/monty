#include "monty.h"

/**
  * rotrOp - Rotates the stack.
  * @stack: Pointer to the top of the stack.
  * @line_number: Not used (casted to void)
 */

void rotrOp(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	for (temp = *stack; temp->next != NULL; temp = temp->next)
		;
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
