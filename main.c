#include "monty.h"

/**
 * main - Entry point
 * @argc: number of arguments passed
 * @argv: Array of pointers to the arguments passed
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char **argv)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"nop", nopOp},
		{"pint", pintOp},
		{"pop", popOp},
		{"swap", swapOp},
		{"add", addOp},
		{"sub", subOp},
		{"div", divOp},
		{"mul", mulOp},
		{"mod", modOp},
		{"pchar", pcharOp},
		{"pstr", pstrOp},
		{"rotl", rotlOp},
		{NULL, NULL}
	};
	FILE *fp = fopen(argv[1], "r");
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	processFile(fp, &stack, instructions);
	freeMem(&stack);
	fclose(fp);
	return (EXIT_SUCCESS);
}
