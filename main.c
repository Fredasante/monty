#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point of the program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on successful exit
 */

int main(int argc, char **argv)
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
open_file(argv[1]);
free_nodes();
return (0);
}
