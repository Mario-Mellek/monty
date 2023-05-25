#include "monty.h"

char *getNewLine(FILE *fp)
{
	char *line = (char *)malloc(MAX_LINE_LENGTH);

	if (!line)
	{
		return (NULL);
	}
	if (fgets(line, MAX_LINE_LENGTH, fp))
	{
		return (line);
	}
	free(line);
	return (NULL);
}

