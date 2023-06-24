#ifndef MONTY_H
#define MONTY_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef void (*stack_func)(stack_t **, unsigned int);
char *parse_ln(char *line);
void push_to_stack(stack_t **stack, unsigned int line_num);
void pall_stack(stack_t **stack, unsigned int line_num);
void pint_stack(stack_t **stack, unsigned int line_num);
void pop_stack(stack_t **stack, unsigned int line_num);
void swap_stack(stack_t **stack, unsigned int line_num);
void add_stack(stack_t **stack, unsigned int line_num);
void mod_stack(stack_t **stack, unsigned int line_num);
void sub_stack(stack_t **stack, unsigned int line_num);
void div_stack(stack_t **stack, unsigned int line_num);
void mul_stack(stack_t **stack, unsigned int line_num);
void pchar_stack(stack_t **stack, unsigned int line_num);
void pstr_stack(stack_t **stack, unsigned int line_num);
stack_func op_func(char *opcode);
void run_instructions(FILE *fl, stack_t **stack);
void free_dlistint(stack_t *head);
void exit_on_error(stack_t **stack);
int isnum(char *param);
#endif
