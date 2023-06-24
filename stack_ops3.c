#include "monty.h"
/**
 * pchar_stack - prints corresponding ascii of the top element in a stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void pchar_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit_on_error(stack);
	}
	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit_on_error(stack);
	}
	printf("%c\n", tmp->n);
}

/**
 * pstr_stack - prints corresponding ascii of all elements in a stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void pstr_stack(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl_stack - the first element of the stack becomes the last
 *
 * @stack: the stack
 * @line_num: the line number of the instruction
 *
 * Return: nothing
 */
void rotl_stack(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp = *stack, *second;

	if (tmp)
		second = tmp->next;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp && second)
	{
		tmp->next = *stack;
		tmp->next->prev = tmp;
		tmp->next->next = NULL;
		*stack = second;
		second->prev = NULL;
	}
}

/**
 * rotr_stack - the last element of the stack becomes the top
 *
 * @stack: the stack
 * @line_num: the line number of the instruction
 *
 * Return: nothing
 */
void rotr_stack(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp = *stack;

	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp && tmp->prev)
	{
		tmp->prev->next = NULL;
		tmp->next = *stack;
		tmp->next->prev = tmp;
		tmp->prev = NULL;
		*stack = tmp;
	}
}
