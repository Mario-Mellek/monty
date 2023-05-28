#include "monty.h"

void pstrOp(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;

	for (temp = *stack; temp != NULL && temp->n != 0
			&& temp->n > 0 && temp->n <= 127;
			temp = temp->next)
	{
		printf("%c", temp->n);
	}
	printf("\n");
}
