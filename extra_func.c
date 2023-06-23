#include "monty.h"
/**
 * *_strdup - returns pointer which contains copy of string
 *
 * @str: string
 * Return: char
 */

char *_strdup(char *str)
{
	char *new;

	if (str == NULL)
	{
		return (NULL);
	}
	new = malloc(strlen(str) + 1);

	if (new == NULL)
	{
		return (NULL);
	}
	strcpy(new, str);
	return (new);

}
