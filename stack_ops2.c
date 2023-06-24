#include "monty.h"
/**
 * add_stack - adds the top 2 elements of stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void add_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack, *tmp_next;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit_on_error(stack);
	}
	tmp_next = tmp->next;
	tmp_next->n += tmp->n;

	pop_stack(stack, line_num);
}
