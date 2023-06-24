#include "monty.h"

/**
 * push_to_stack - adds a new stack element
 *
 * @stack: the stack to push to
 * @line_num: line number of the instruction
 *
 * Return: void
 */
void push_to_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *new;
	char *param;

	param = strtok(NULL, "\t\n ");
	if (!param || isnum(param) == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit_on_error(stack);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "malloc failed %d\n", line_num);
		exit_on_error(stack);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = atoi(param);
	*stack = new;
}

/**
 * pall_stack - print elements in a stack from top
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void pall_stack(stack_t **stack, __attribute__((unused))unsigned int line_num)
{
	stack_t *tmp = *stack;

	/*if (!tmp)*/
	/*{*/
		/*fprintf(stderr, "The stack is empty %d\n", line_num);*/
		/*exit_on_error(stack);*/
	/*}*/
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint_stack - prints the top elements in a stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void pint_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit_on_error(stack);
	}
	printf("%d\n", tmp->n);
}

/**
 * pop_stack - prints the top elements in a stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void pop_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit_on_error(stack);
	}
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}

/**
 * swap_stack - prints the top elements in a stack
 *
 * @stack: stack to print
 * @line_num: line number of instruction to print
 *
 * Return: nothing
 */
void swap_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack, *tmp_next;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit_on_error(stack);
	}
	tmp_next = tmp->next;
	tmp->next = tmp_next->next;
	tmp_next->next->prev = tmp;
	tmp->prev = tmp_next;
	tmp_next->prev = NULL;
	tmp_next->next = tmp;
	*stack = tmp_next;
}
