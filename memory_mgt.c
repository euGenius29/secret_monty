#include "monty.h"
/**
 * pop_all - frees all memories before exit;
 * @stack: head pointer
 * Return (void)
 */
void pop_all(stack_t *stack)
{
	while (stack != NULL)
	{
		pop(&stack, 0);
	}
}
