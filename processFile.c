#include "monty.h"

/**
 * processFile - Processes a file line by line
 * @fp: Pointer to the file to be processed.
 * @stack: Pointer to the top of the stack.
 * @instructions: Array of valid functions.
 */


void processFile(FILE *fp, stack_t **stack, instruction_t instructions[])
{
	char line[256];
	size_t i = 0;

	while (fgets(line, sizeof(line), fp) != NULL)
	{
		i++;
		checkOps(line, i, stack, instructions);
	}
}
