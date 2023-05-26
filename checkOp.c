#include "monty.h"

/**
 * checkOps - Checks and executes the corresponding operation.
 * @line: The line containing the opcode.
 * @line_number: The line number being passed.
 * @stack: Pointer to the top of the stack.
 * @instructions: Array of valid instructions.
 */

void checkOps(char *line, unsigned int line_number,
		stack_t **stack, instruction_t instructions[])
{
	char *opCode = NULL;
	int i, codeExists = 0;

	if (line[0] == '\n' || line[0] == '#' || line[0] == ' ')
		return;

	opCode = strtok(line, " \t\n");
	if (!opCode)
		return;

	for (i = 0, codeExists = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opCode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			codeExists = 1;
			break;
		}
	}
	if (!codeExists)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, opCode);
		exit(EXIT_FAILURE);
	}
}
