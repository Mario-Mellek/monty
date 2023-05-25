#include "monty.h"

/**
 * processFile - Processes a file line by line.
 * @fp: file pointer
 */

void processFile(FILE *fp)
{
	size_t i, j = 0;
	char *opCode, *line = NULL;
	int opExists;
	instruction_t instructions[] = {
		{"push", NULL},
		{"pall", NULL},
		{"nop", nopOp},
		{NULL, NULL}
	};
	for (i = 0, line = getNewLine(fp); line != NULL;
			i++, line = getNewLine(fp))
	{
		skipLine(line);
		if (line[0] == '\n' || line[0] == '#')
		{
			continue;
		}
		opCode = strtok(line, "\t \n");
		if (!opCode)
		{
			free(line);
			continue;
		}
		opExists = checkOpCode(opCode, instructions, j, i);
		if (opExists == EXIT_FAILURE)
		{
			free(line);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
		free(line);
	}
	printf("Successfully Read\n");
}
