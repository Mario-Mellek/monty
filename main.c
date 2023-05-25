#include "monty.h"
#include <unistd.h>


instruction_t instructions[] = {
	{"push", NULL},
	{"pall", NULL},
	{"nop", NULL},
	{NULL, NULL}
};

int main(int argc, char **argv)
{
	FILE *fp = fopen(argv[1], "r");
	size_t i, j, len = 0;
	char *opCode, *line = NULL;
	ssize_t read;
	int opExists;

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


	for (i = 0; (read = getline(&line, &len, fp)) != -1; i++)
	{
		if (line[0] == '\n' || line[0] == '#')
		{
			printf("Skipped\n");
			continue;
		}
		opCode = strtok(line, "\t \n");
		if (!opCode)
			continue;
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
			return (EXIT_FAILURE);
		}
	}
	printf("Successfully Read: %s\n", argv[1]);
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}
