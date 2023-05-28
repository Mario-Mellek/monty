#include "monty.h"

/**
 * pstrOp - Prints the string starting at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Not used (casted to void)
 */

void pstrOp(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	if ((*stack) == NULL)
	{
		printf("0\n");
		return;
	}
	for (temp = *stack; temp != NULL && temp->n != 0
			&& temp->n > 0 && temp->n <= 127;
			temp = temp->next)
	{
		printf("%c", temp->n);
	}
	printf("\n");
	if ((*stack)->next == NULL)
	{
		printf("0\n");
	}
}
