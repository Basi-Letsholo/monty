#include "monty.h"
/**
 * free_ptr - frees memory from ptr
 * @ptr: pointer to free
 */

void free_ptr(char **ptr)
{
	int index;

	for (index = 0; ptr[index] != NULL; index++)
	{
		free(ptr[index]);
	}
	free(ptr);
}
