#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - entry point of program
 *
 * @argc: number of arguments passed
 * @argv: values of arguments passed
 *
 * Return: 0 on success and 1 on failure
 */
int  main(int argc, char **argv)
{
		FILE *fl;
		stack_t *top = NULL;

		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file\n");
			exit_on_error(&top);
		}
		fl = fopen(argv[1], "r");
		if (!fl)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit_on_error(&top);
		}
		run_instructions(fl, &top);
		free_dlistint(top);
		return (EXIT_SUCCESS);
}
