#include "monty.h"

/**
 * execute_instruction - checks and executes appropriate instruction
 * @opcode: opcode
 * @stack: appropriate opcode command to execute
 * @line_number: line number in file
 */
instruction_t instruction_list[] = {
	{"push", push},
	{"pop", pop},
	{"pall", pall},
	{"pint", pint},
	{"swap", swap},
	{"sub", sub},
	{"add", add},
	{"nop", nop}
};

int execute_instruction(char *opcode, stack_t **stack,
		unsigned int line_number)
{
	size_t i, j;

	j = sizeof(instruction_list) / sizeof(instruction_list[0]);
	for (i = 0; i < j; ++i)
	{
		if (strcmp(opcode, instruction_list[i].opcode) == 0)
		{
			instruction_list[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * push - pushes data to the top of the stack.
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return void
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node, *last;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	new_node->next = NULL;

	if ((*stack) == NULL)
	{
		new_node->prev = NULL;
		(*stack) = new_node;
	}
	else
	{
		last = (*stack);
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
}

/**
 * pop - deletes the last node
 * @stack: head pointer
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *previous;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	if (temp->next == NULL)
	{
		free(temp);
		(*stack) = NULL;
		return;
	}

	previous = NULL;
	while (temp->next != NULL)
	{
		previous = temp;
		temp = temp->next;
	}

	if (previous != NULL)
	{
		previous->next = NULL;
	}
	free(temp);
}
/**
 * pall - prints all elements of the stack
 * @stack: head pointer
 * @line_number: line number of file
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	if ((*stack) == NULL)
		return;
	current = (*stack);
	while (current->next != NULL)
	{
		current = current->next;
	}
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}

/**
 * pint - prints the data at thetop of the stack
 * @stack: head pointer
 * @line_number: line number of file
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
		(*stack) = (*stack)->next;
	printf("%d\n", (*stack)->n);
}
