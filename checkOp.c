#include "monty.h"

/**
 * checkOpCode - Checks if an opcode exists in the instruction set.
 * @opCode: The opcode to check.
 * @instructions: An array of instructions to check against.
 * @j: The current index of the array of instructions.
 * @i: The current line number of the file being processed.
 * Return: EXIT_SUCCESS if the opcode exists in the instruction set, or
 * EXIT_FAILURE if the opcode is not recognized.
 */

int checkOpCode(char *opCode, instruction_t *instructions, size_t j, size_t i)
{
	int opExists = 0;

	for (j = 0; instructions[j].opcode != NULL; j++)
	{
		if (strcmp(opCode, instructions[j].opcode) == 0)
		{
			opExists = 1;
			printf("Exists\n");
			break;
		}
	}
	if (!opExists)
	{
		fprintf(stderr, "L%lu: unknown instruction %s\n", i, opCode);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
