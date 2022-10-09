#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void push_to_stack(stack_t **new_node, unsigned int line_num);
void display(stack_t **stack, unsigned int line_num);
void get_func(char *op, char *data, unsigned int line_num, int);
void call_func(op_func f, char *op, char *data, unsigned int line_num, int);
stack_t *create_node(int n);
void open_file(char *filename);
void read_file(FILE *fd);
int parse_line(char *line, unsigned int line_num, int);
void free_nodes(void);
void print_top(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void do_nothing(stack_t **stack, unsigned int line_number);
void remove_top(stack_t **stack, unsigned int line_number);
void sum_nodes(stack_t **stack, unsigned int line_number);
void sub_nodes(stack_t **stack, unsigned int line_num);
void div_nodes(stack_t **stack, unsigned int line_num);
void mul_nodes(stack_t **stack, unsigned int line_num);
void mod_nodes(stack_t **stack, unsigned int line_num);
void pchar_node(stack_t **stack, unsigned int line_num);
void pstr_nodes(stack_t **stack, unsigned int line_num);
void rotate_top(stack_t **stack, unsigned int line_num);
void rotate_bottom(stack_t **stack, unsigned int line_num); 
#endif
