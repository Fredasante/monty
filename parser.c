#include "monty.h"

/**
 * open_file - opens a file
 * @filename: name of file to open
 */

void open_file(char *filename)
{
FILE *fd;
int file_check;
if (filename == NULL)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file_check = access(filename, R_OK);
if (file_check == -1)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
fd = fopen(filename, "r");
if (fd == NULL)
{
fprintf(stderr, "Error: can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
read_file(fd);
fclose(fd);
}

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor of open file
 */

void read_file(FILE *fd)
{
char line[100];
unsigned int line_num;
int format;
format = 0;
for (line_num = 1; fgets(line, 100, fd) != NULL; line_num++)
{
format = parse_line(line, line_num, format);
}
}

/**
 * parse_line - parses line read and divides it into opcode and data
 * @line:  string to parse
 * @line_num: line number of the string to be parsed
 * @format: format specifier, 0 if stack, 1 if queue
 * Return: 0 if stack, 1 if queue
 */

int parse_line(char *line, unsigned int line_num, int format)
{
char *opcode;
char *data;

if (line)
{
opcode = strtok(line, "\n ");
if (opcode == NULL)
return (format);
data = strtok(NULL, "\n ");
}
if (strcmp(opcode, "queue") == 0)
return (1);
else if (strcmp(opcode, "stack") == 0)
return (0);
get_func(opcode, data, line_num, format);
return (format);
}
