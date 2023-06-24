#include "monty.h"
#include <ctype.h>

/**
 * parse_ln - parses an instruction line
 *
 * @line: the line to parse
 *
 * Return: opcode or NULL if failed
 */
char *parse_ln(char *line)
{
		char *opcode;

		opcode = strtok(line, "\t\n ");
		if (!opcode)
			return (NULL);
		return (opcode);
}

/**
 * op_func - gets the functions to call for instruction
 *
 * @opcode: instruction to get func
 *
 * Return: pointer to a function
 */
stack_func op_func(char *opcode)
{
	int i = 0;
	instruction_t inst[] = {
		{"push", push_to_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{NULL, NULL}
	};
	while (inst[i].f && strcmp(opcode, inst[i].opcode) != 0)
		i++;
	return (inst[i].f);
}

/**
 * exit_on_error - exits the program after free memories
 *
 * @stack: pointer to the top of the stack
 *
 * Return: void
 */
void exit_on_error(stack_t **stack)
{
	free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
 * free_dlistint - frees a doubly linked list
 *
 * @head: head of the doubly linked list
 *
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *current = head;

	while (current)
	{
		head = current->next;
		free(current);
		current = head;
	}
}

/**
 * isnum - checks if a string is a valid number
 *
 * @param: string to check
 *
 * Return: -1 on failure and 0 on success
 */
int isnum(char *param)
{
	char *str = param;
	unsigned int i;

	if (!str)
		return (-1);
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}
