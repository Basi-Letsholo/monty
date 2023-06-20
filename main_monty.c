#include "monty.h"

int main(int ac, char **av)
{
    /* init vars*/
    (void)av;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit (EXIT_FAILURE);
    }

    return (0);
}