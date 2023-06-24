#include "monty.h"
/**
 * free_ptr - frees memory from ptr
 * @ptr: pointer to free
 */

void free_ptr(char **ptr)
{
	int index = 0;

	while (ptr[index] != NULL)
	{
		free(ptr[index]);
		index++;
	}
	free(ptr);
}
