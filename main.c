#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp = fopen(argv[1], "r");

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
	printf("%s\n", argv[1]);
	return (0);
}
