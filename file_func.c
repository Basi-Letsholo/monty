#include "monty.h"

/**
 * _open - opens file
 * @filename: file name
 * Return: open_file int
 */

int _open(char *filename)
{
	int open_file;

	open_file = open(filename, O_RDONLY);
	if (open_file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (open_file);
}

/**
 * read_file - reads file and counts lines
 * @open_file: file descriptor
 * @size_of_file: size of file in bytes
 * @file_text: text in file
 * Return: lines in file, exit if error
 */

int read_file(int open_file, off_t size_of_file, char *file_text)
{
	int lines_in_file = 0, i;
	ssize_t bytes_read;

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
		free(file_text);
		close(open_file);
		exit(EXIT_FAILURE);
	}

	return (lines_in_file);
}

/**
 * size_by_line - finds the size in bytes of each line
 * @open_file: file descriptor
 * @lines_in_file: lines in file
 * Return: array of size by line
 */

int *size_by_line(int open_file, int lines_in_file, char *file_text)
{
	off_t reposition;
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];
	int line_size = 0, *save_line_size, current_line = 0, i;
	(void)reposition;

	save_line_size = (int *)malloc(sizeof(int) * lines_in_file);
	reposition = lseek(open_file, 0, SEEK_SET);
	while ((bytes_read = read(open_file, buffer, BUFFER_SIZE)) > 0)
	{
		for (i = 0; i < bytes_read; i++)
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
	if (bytes_read == -1)
	{
		/* STDERR MSG */
		close(open_file);
		free(file_text);
		exit(EXIT_FAILURE);
	}

	return (save_line_size);
}
