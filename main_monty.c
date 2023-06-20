#include "monty.h"

int main(int ac, char **av)
{
	int open_file;
	ssize_t bytes_read;
/*	stack_t *current = NULL;*/
	char *file_text = NULL;
	off_t size_of_file;
	struct stat file_stat;
	/* init vars */

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

	size_of_file = fstat(open_file, &file_stat);
	if (size_of_file == -1)
	{
		/** STDERR MSG */
		close(open_file);
		exit(EXIT_FAILURE);
	}
	printf("file size = %ld\n", size_of_file);

	file_text = (char *)malloc(size_of_file + 1);
	if (file_text == NULL)
	{
		/* STDERR MSG */
		close(open_file);
		exit(EXIT_FAILURE);
	}
	bytes_read = read(open_file, file_text, size_of_file);
	if (bytes_read == -1)
	{
		/* STDERR MSG */
		close(open_file);
		free(file_text);
		exit(EXIT_FAILURE);
	}

	printf("File read: %d\n", file_text[0]);

	close(open_file);

	free(file_text);
	return (0);
	/* change later?? */
}
