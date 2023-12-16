#include "monty.h"

/**
 * mul - multiplied the first two data
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int temp_data;
	stack_t *temp;

	if (count_stacks(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	while (temp->prev != NULL)
	{
		temp = temp->prev;
	}
	temp_data = (temp->n) * (temp->next->n);
	temp->next->n = temp_data;
	(*stack) = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	free(temp);
}
/**
 * divide - multiplied the first two data
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int temp_data;
	stack_t *temp;

	if (count_stacks(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	while (temp->prev != NULL)
	{
		temp = temp->prev;
	}
	temp_data = (temp->n) / (temp->next->n);
	temp->next->n = temp_data;
	(*stack) = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	free(temp);
}
/**
 * mod - finds the modulo or reminder of the first two data
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Description: Finds the modulo or reminder of two
 *		element on the stack
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int temp_data;
	stack_t *temp;

	if (count_stacks(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	while (temp->prev != NULL)
	{
		temp = temp->prev;
	}
	temp_data = (temp->n) * (temp->next->n);
	temp->next->n = temp_data;
	(*stack) = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	free(temp);
}
