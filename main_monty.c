#include "monty.h"

int main(int ac, char **av)
{
	int open_file, lines_in_file = 0, i = 0, save_line_size[BUFFER_SIZE], line_size = 0;
	int current_line = 0;
	ssize_t bytes_read, bytes_read2;
	stack_t *current = NULL;
	char *file_text = NULL, *token = NULL, **split_text = NULL, buffer[BUFFER_SIZE];
	char *file_cp = NULL;
	off_t size_of_file, reposition;
	struct stat file_stat;
	/* init vars */
	(void)reposition;

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
	printf("file size = %ld\n", size_of_file);

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
	printf("File read: %s\n", file_text);
	printf("Lines: %d\n", lines_in_file);

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

	for (i = 0; i < lines_in_file; i++)
	{
		printf("size per line, %d: %d\n", i, save_line_size[i]);
	}
	split_text = malloc(sizeof(char *) * lines_in_file);

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
	for (i = 0; i < lines_in_file; i++)
	{
		printf("Line %d: %s\n", i, split_text[i]);
	}

	/* STACKS START HERE */
	for (i = 

	for (i = 0; i < lines_in_file; i++)
	{
		free(split_text[i]);
	}
	free(file_text);
	close(open_file);
	return (0);
	/* change later?? */
}
