#include "monty.h"

int main(int ac, char **av)
{
	int open_file, lines_in_file = 0, i = 0, k, *save_line_size = NULL, new_num_lines;
	size_t j;
	unsigned int line_number;
	stack_t *stack = NULL;
	char *file_text = NULL, *token = NULL, *token2 = NULL, **split_text = NULL;
	char *file_cp = NULL, *current_opcode = NULL, **array_text = NULL;
	off_t size_of_file;
	struct stat file_stat;
	int mem_count = 0; /* DELETE LATER!! USE to find out how much mem needs to be freed at each point */
/*	instruction_t opcodes[] = { 
	{"push", push_opcode},
	{"pall", pall_opcode}
	};*/
	/* init vars */
	(void)j;
	(void)line_number;
	(void)current_opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file = _open(av[1]);

	if (stat(av[1], &file_stat) == 0)
	{
		size_of_file = file_stat.st_size;
	}

	file_text = malloc(size_of_file + 1);
	mem_count += 1;
	if (file_text == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close(open_file);
		exit(EXIT_FAILURE);
	}

	lines_in_file = read_file(open_file, size_of_file, file_text);
	save_line_size = size_by_line(open_file, lines_in_file, file_text); 
	mem_count += 1;

	file_text[size_of_file] = '\0';
	split_text = malloc(sizeof(char *) * lines_in_file);
	if (split_text == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(file_text);
		free(save_line_size);
		close(open_file);
		exit(EXIT_FAILURE);
	}
	mem_count += 1;

	for (i = 0; i < lines_in_file; i++)
	{
		split_text[i] = NULL;
	}

	file_cp = strdup(file_text);
	mem_count += 1;

	token = strtok(file_cp, "\n");
	mem_count+= 1;

	i = 0;
	while (token != NULL)
	{
		split_text[i] = malloc(strlen(token) + 1);
		if (split_text[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(split_text);
			free(file_cp);
			free(token);
			free(file_text);
			free(save_line_size);
			close(open_file);
			exit(EXIT_FAILURE);
		}

		strcpy(split_text[i], token);
		i++;
		token = strtok(NULL, "\n");	
	}	
	
	array_text = malloc(sizeof(char *) * lines_in_file * 2);
	if (array_text == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(file_cp);
		free(token);
		free(file_text);
		free(save_line_size);
		free_ptr(split_text);
/*		free_ptr(array_buff);*/
		close(open_file);
		exit(EXIT_FAILURE);
	}
	mem_count += 1;

	k = 0;
	for (i = 0; i < lines_in_file; i++)
	{
		token2 = strtok(split_text[i], " ");
		while (token2 != NULL)
		{
			array_text[k] = malloc(strlen(token2) + 1);
			if (array_text[k] == NULL)
			{
				/* error handling */
				exit(EXIT_FAILURE);
			}
			strcpy(array_text[k], token2);
			k++;
			token2 = strtok(NULL, " ");
		}
	}
	new_num_lines = k;

	/* STACKS START HERE , and so do mem issues */

	for (i = 0; i < new_num_lines; i++)
	{
		if (strcmp(array_text[i], "push") == 0)
		{
			push_opcode(&stack, atoi(array_text[i + 1]));
		}
		if (strcmp(array_text[i], "pall") == 0)
		{
			pall_opcode(&stack, 0);
		}
		else
		{
			i += 1;
		}
	}
/*	for (i = 0; i < new_num_lines; i++)
	{

		strncpy(array_text[i], current_opcode, 4);

		printf("Test!\nopcode: %s\n", current_opcode);

		for (k = 0; k < new_num_lines; k++)
		{	
			line_number = 1;
			for (j = 0; j < sizeof(opcodes) / sizeof(opcodes[0]); j++)
			{
				if (strcmp(current_opcode, opcodes[j].opcode) == 0)
				{
					 opcodes[k].f(stack, line_number);
					 break;
				}
			}
			line_number++;

		}
	}
*/
/*	current_opcode = "pall";
	for (j = 0; j < sizeof(opcodes) / sizeof(opcodes[0]); j++)
                 {       
                        if (strcmp(current_opcode, opcodes[i].opcode) == 0)
			{        
                                  opcodes[i].f(stack, line_number);
                                  break;
                         }
		}
	}
*/
/*	while (*stack != NULL)
	{
		free(*stack);
		*stack = (*stack)->next;
	}
*/

/*	free_ptr(split_text);*/
	/*free_ptr(array_text);*/
/*	free_ptr(array_buff);*/
	free(file_text);
	free(save_line_size);
	/* Later - write func to free everything at once */
	close(open_file);

	return (0);
	/* change later?? */
}
