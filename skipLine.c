#include "monty.h"

/**
 * skipLine - Skips empty lines and comments
 * @line: The line to be skipped
 */

void skipLine(char *line)
{
	if (line[0] == '\n' || line[0] == '#')
	{
		printf("Skipped\n");
		free(line);
	}
}
