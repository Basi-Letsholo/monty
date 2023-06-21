#include "monty.h"

/**
 * rem_extraspace - removes extraspace in commandline
 * @input: user input
 * Return: input w/o extra space
 */
char *rem_extraspace(char *input)
{
	int i, j = 0, len, count = 0, front = 1;

	len = strlen(input);

	while (input[j] == ' ')
	{
		j++;
	}
	if (j == len)
	{
		input[0] = ' ';
		input[1] = '\0';
		return (input);
	}
	for (i = j; i < len; i++)
	{
		if (input[i] != ' ')
		{
			input[j] = input[i];
			j++;
			count = 0;
			front = 0;
		}
		else
		{
			if (count == 0 && front == 0)
			{
				input[j] = input[i];
				j++;
			}
			count++;
		}
	}
	if (j > 0 && input[j - 1] == ' ')
	{
		j--;
	}
	input[j] = '\0';

	return (input);
}
