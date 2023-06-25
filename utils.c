#include "monty.h"


/**
 * add_dnodeint - adds a node in a stack
 *
 * @head: pointer to pointer of the list head
 * @new: the node to add
 *
 * Return: pointer to the element or NULL
 */
stack_t *add_dnodeint(stack_t **head, stack_t *new)
{
	stack_t *current;

	if (!head)
		return (NULL);
	new->prev = NULL;
	current = *head;
	if (!current)
		new->next = NULL;
	else
	{
		new->next = current;
		current->prev = new;
	}
	*head = new;
	return (new);
}


/**
 * add_dnodeint_end- adds a node at the end of a queue
 *
 * @head: pointer to pointer of the list head
 * @new: the pointer to the newly created node
 *
 * Return: pointer to the element or NULL
 */
stack_t *add_dnodeint_end(stack_t **head, stack_t *new)
{
	stack_t *current;

	if (!head)
		return (NULL);
	current = *head;
	new->next = NULL;
	if (!current)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (current->next)
		current = current->next;
	new->prev = current;
	current->next = new;
	return (new);
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
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", pchar_stack},
		{"pstr", pstr_stack},
		{"rotl", rotl_stack},
		{"rotr", rotl_stack},
		{"stack", stack},
		{"queue", queue},
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
