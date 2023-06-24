#define _GNU_SOURCE
#include "monty.h"

/**
 * run_instructions - scans bytecode file and runs instructions
 *
 * @fl: file stream
 * @stack: stack to work with
 *
 * Return: void
 */
void run_instructions(FILE *fl, stack_t **stack)
{
		char *line = NULL, *opcode;
		size_t n = 0;
		ssize_t chr_read;
		stack_func f;
		unsigned int line_num = 0;

		while ((chr_read = getline(&line, &n, fl)) != -1)
		{
			line_num++;
			if (*line == '#')
				continue;
			opcode = parse_ln(line);
			if (!opcode || strcmp(opcode, "nop") == 0)
				continue;
			f = op_func(opcode);
			if (!f)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
				exit(EXIT_FAILURE);
			}
			f(stack, line_num);
		}
		free(line);
		fclose(fl);
}
