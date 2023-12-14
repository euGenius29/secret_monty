#include "monty.h"
/**
 * count_stacks - counts the number of elements in the stack
 * @stack: head pointer
 * Return: number of elements
 */
int count_stacks(stack_t **stack)
{
	stack_t *temp;
	int count;

	count = 1;
	if ((*stack) == NULL)
		return (0);
	temp = (*stack);
	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	printf("count is %d elements\n", count);
	return (count);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (count_stacks(temp) < 2)
		fprintf
	if ((*stack)->next != NULL)
		(*stack) = stack->next;
	temp = (*stack)->n;
	(*stack)->n = ((*stack)->prev->n);
	((*stack)->prev->n) = temp;
}

