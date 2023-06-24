#include "monty.h"
/**
 * push_opcode - push function
 * @stack: stack/linked list
 * @line_number: line number
 */

void push_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		/* FREE MEM */
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
	printf("Test\n");
}

/**
 * pall_opcode - prints current stack
 * @stack: stack
 * @line_number: line number of command
 */

void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	(void)line_number;

	current = *stack;
	if (current == NULL)
	{
		return;
	}

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint_opcode - prints top stack
 * @stack: stack
 * @line_number: line number
 */

void pint_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		/* Free mem */
		/*exit(EXIT_FAILURE);*/
		exit(EXIT_FAILURE);
	}

	printf("%d\n", current->n);
}

/**
 * pop_opcode - deletes top element form stack
 * @stack: stack
 * @line_number: line_number
 */

void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	current = *stack;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		/* FREE MEM */
		exit(EXIT_FAILURE);
	}
	if (current->next == NULL)
	{
		*stack = NULL;
		return;
	}
	current = current->next->next;
	current->prev = NULL;
}
