#define _GNU_SOURCE
#include "monty.h"
#include <ctype.h>

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
			opcode = parse_ln(line);
			if (!opcode || strcmp(opcode, "nop") == 0 || opcode[0] == '#')
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
