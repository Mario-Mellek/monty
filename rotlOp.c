#include "monty.h"

void rotlOp(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;

	for (temp = *stack; temp->next != NULL; temp = temp->next)
		;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
