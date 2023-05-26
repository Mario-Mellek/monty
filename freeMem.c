#include "monty.h"

/**
 * freeMem - Frees the memory allocated for the stack.
 * @stack: A pointer to the stack.
 */

void freeMem(stack_t **stack)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
		return;
	for (temp = (*stack); (*stack) != NULL; temp = temp->next)
	{
		(*stack) = (*stack)->next;
		free(temp);
	}
}
