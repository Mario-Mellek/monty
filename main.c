#include "monty.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *fp = fopen(argv[1], "r");
	size_t i, j = 0;
	char *opCode, *line = NULL;
	int opExists;
	instruction_t instructions[] = {
		{"push", NULL},
		{"pall", NULL},
		{"nop", NULL},
		{NULL, NULL}
	};

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

	for (i = 0, line = getNewLine(fp); line != NULL;
			i++, line = getNewLine(fp))
	{
		if (line[0] == '\n' || line[0] == '#')
		{
			printf("Skipped\n");
			free(line);
			continue;
		}
		opCode = strtok(line, "\t \n");
		if (!opCode)
		{
			free(line);
			continue;
		}
		for (j = 0, opExists = 0; instructions[j].opcode != NULL; j++)
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
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	printf("Successfully Read: %s\n", argv[1]);
	fclose(fp);
	return (EXIT_SUCCESS);
}
