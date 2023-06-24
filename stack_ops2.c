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

/**
 * sub_stack - substracts the top 2 elements of stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void sub_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack, *tmp_next;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit_on_error(stack);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: Division by zero\n", line_num);
		exit_on_error(stack);
	}
	tmp_next = tmp->next;
	tmp_next->n -= tmp->n;

	pop_stack(stack, line_num);
}

/**
 * div_stack - divides the top 2 elements of stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void div_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack, *tmp_next;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit_on_error(stack);
	}
	tmp_next = tmp->next;
	tmp_next->n /= tmp->n;

	pop_stack(stack, line_num);
}

/**
 * mul_stack - multiplies the top 2 elements of stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void mul_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack, *tmp_next;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit_on_error(stack);
	}
	tmp_next = tmp->next;
	tmp_next->n *= tmp->n;

	pop_stack(stack, line_num);
}

/**
 * mod_stack - modulus of the top 2 elements of stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void mod_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack, *tmp_next;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit_on_error(stack);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: Division by zero\n", line_num);
		exit_on_error(stack);
	}
	tmp_next = tmp->next;
	tmp_next->n %= tmp->n;

	pop_stack(stack, line_num);
}
