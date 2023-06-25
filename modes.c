#include "monty.h"

/**
 * stack - sets the mode of the program to use queues
 *
 * @stack: the queue to work with
 * @line_num: the line number of the instruction
 *
 * Return: nothing
 */
void stack(__attribute__ ((unused)) stack_t **stack,
					    __attribute__ ((unused)) unsigned int line_num)
{
	mode = 0;
}

/**
 * queue - sets the mode of the program to use queues
 *
 * @stack: the queue to work with
 * @line_num: The line number of then instruction
 *
 * Return: nothing
 */
void queue(__attribute__ ((unused))stack_t **stack,
					    __attribute__ ((unused))unsigned int line_num)
{
	mode = 1;
}
