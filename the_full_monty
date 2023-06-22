#include "monty.h"

int main(int ac, char **av)
{
	int open_file, lines_in_file = 0, i = 0, save_line_size[BUFFER_SIZE], line_size = 0;
	int current_line = 0, count = 0, k;
	ssize_t bytes_read, bytes_read2;
	size_t j;
	unsigned int line_number;
	stack_t **stack = NULL;
	char *file_text = NULL, *token = NULL, **split_text = NULL, buffer[BUFFER_SIZE];
	char *file_cp = NULL, *current_opcode = NULL, **array_text = NULL;
	char **array_buff = NULL;
	off_t size_of_file, reposition;
	struct stat file_stat;
	instruction_t opcodes[] = { 
	{"push", push_opcode},
	{"pall", pall_opcode}
	};
	/* init vars */
	(void)reposition;
	(void)save_line_size;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file = open(av[1], O_RDONLY);
	if (open_file == -1)
	{
		/* STDERR */
		exit(EXIT_FAILURE);
	}

	if (stat(av[1], &file_stat) == 0)
	{
		size_of_file = file_stat.st_size;
	}

	/* DELETE NEXT LINE */
/*	printf("file size = %ld\n", size_of_file);*/

	file_text = malloc(size_of_file + 1);
	if (file_text == NULL)
	{
		/* STDERR MSG */
		close(open_file);
		exit(EXIT_FAILURE);
	}
	while ((bytes_read = read(open_file, file_text, size_of_file)) > 0)
	{
		for (i = 0; i < size_of_file; i++)
		{
			if (file_text[i] == '\n')
			{
				lines_in_file++;
			}
			
		}
	}
	if (bytes_read == -1)
	{
		/* STDERR MSG */
		close(open_file);
		free(file_text);
		exit(EXIT_FAILURE);
	}

	/* DELETE NEXT LINE */
/*	printf("File read: %s\n", file_text);
	printf("Lines: %d\n", lines_in_file);
*/
/*	file_cp = strdup(file_text, 5);*/

	reposition = lseek(open_file, 0, SEEK_SET);
	while ((bytes_read2 = read(open_file, buffer, BUFFER_SIZE)) > 0)
	{
		for (i = 0; i < bytes_read2; i++)
		{
			if (buffer[i] != '\n')
			{
				line_size++;
			}
			else
			{
				save_line_size[current_line++] = line_size;
				line_size = 0;
			}
		}
	}
	if (bytes_read2 == -1)
	{
		/* STDERR MSG */
		close(open_file);
		free(file_text);
		exit(EXIT_FAILURE);
	}

/*	for (i = 0; i < lines_in_file; i++)
	{
		printf("size per line, %d: %d\n", i, save_line_size[i]);
	}*/
	split_text = malloc(sizeof(char *) * lines_in_file);
	if (split_text == NULL)
	{
		/*errors and frees */
		exit(EXIT_FAILURE);
	}
	file_cp = _strdup(file_text);
	token = strtok(file_cp, "\n");
	i = 0;
	while (token != NULL)
	{
		split_text[i] = malloc(strlen(token) + 1);
		if (split_text[i] == NULL)
		{
			/* STD ERR MSG */
			close(open_file);
			free(split_text);
			free(file_text);
			exit(EXIT_FAILURE);
		}

		strcpy(split_text[i], token);
		i++;
		token = strtok(NULL, "\n");	
	}


	array_buff = malloc(sizeof(char *) * lines_in_file);
	if (array_buff == NULL)
	{
		/* HANDLE ERROR */
		exit(EXIT_FAILURE);
	}
	for (i = 0; split_text[i] != NULL; i++)
	{
		array_buff[i] = _strdup(split_text[i]);
		count++;
	}

	array_text = malloc(sizeof(char *) * lines_in_file);
	if (array_text == NULL)
	{
		/* HANDLE ERROR */
		exit(EXIT_FAILURE);
	}
	k = 0;
	for (i = 0; i < count; i++)
	{
		token = strtok(array_buff[i], " ");
		while (token != NULL)
		{
			array_text[i] = malloc(strlen(token) + 1);
			strcpy(array_text[k], token);
			k++;
			token = strtok(NULL, " ");
		}
	}

	for (i = 0; i < lines_in_file; i++)
	{
		printf("%s\n", array_text[i]);
	}

/*	for (i = 0; i < lines_in_file; i++)
	{
		printf("Line %d: %s\n", i, split_text[i]);
	}
*/
	/* STACKS START HERE , and so do mem issues */

	for (i = 0; i < lines_in_file; i++)
	{

	strncpy(split_text[i], current_opcode, 4);
/*	printf("Test!\nopcode: %s\n", current_opcode);*/

		for (i = 0; i < lines_in_file; i++)
		{	
			line_number = 1;
			for (j = 0; j < sizeof(opcodes) / sizeof(opcodes[0]); j++)
			{
				if (strcmp(current_opcode, opcodes[i].opcode) == 0)
				{
					 opcodes[i].f(stack, line_number);
					 break;
				}
			}
			line_number++;

		}
/*	current_opcode = "pall";
	for (j = 0; j < sizeof(opcodes) / sizeof(opcodes[0]); j++)
                 {       
                        if (strcmp(current_opcode, opcodes[i].opcode) == 0)
			{        
                                  opcodes[i].f(stack, line_number);
                                  break;
                         }
			}*/
	}

	while (*stack != NULL)
	{
		free(*stack);
		*stack = (*stack)->next;
	}

	for (i = 0; i < lines_in_file; i++)
	{
		free(split_text[i]);
	}
	free(file_text);
	close(open_file);
	return (0);
	/* change later?? */
}
