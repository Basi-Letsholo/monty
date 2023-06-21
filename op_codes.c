#include "monty.h"
/**
 * push_opcode - push function
 * @stack: stack/linked list
 * @line_number: line number
 */

void push_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = (stack_t *)malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;

/*	if (*stack == new)
	{
		return (*stack);
	}*/
}

/**
 * to Use func:
 * instruction_t opcode_instruction = 
   {
    .opcode = "OPCODE_NAME",
    .f = opcode_func
    };
*/


void pall_opcode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}
