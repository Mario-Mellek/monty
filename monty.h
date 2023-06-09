#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void nopOp(stack_t **stack, unsigned int line_number);
void pintOp(stack_t **stack, unsigned int line_number);
void popOp(stack_t **stack, unsigned int line_number);
void swapOp(stack_t **stack, unsigned int line_number);
void addOp(stack_t **stack, unsigned int line_number);
void subOp(stack_t **stack, unsigned int line_number);
void divOp(stack_t **stack, unsigned int line_number);
void mulOp(stack_t **stack, unsigned int line_number);
void modOp(stack_t **stack, unsigned int line_number);
void pcharOp(stack_t **stack, unsigned int line_number);
void pstrOp(stack_t **stack, unsigned int line_number);
void rotlOp(stack_t **stack, unsigned int line_number);
void rotrOp(stack_t **stack, unsigned int line_number);


void checkOps(char *line, unsigned int line_number,
		stack_t **stack, instruction_t instructions[]);
void processFile(FILE *fp, stack_t **stack, instruction_t instructions[]);
void freeMem(stack_t **stack);

#endif /* MONTY_H */

