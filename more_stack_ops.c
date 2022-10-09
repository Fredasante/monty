#include "monty.h"

/**
 * div_nodes - finds the quotient between the top two nodes
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

void div_nodes(stack_t **stack, unsigned int line_num)
{
int quotient;

if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
exit(EXIT_FAILURE);
}
*stack = (*stack)->next;
if ((*stack)->prev->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_num);
exit(EXIT_FAILURE);
}
quotient = (*stack)->n / (*stack)->prev->n;
(*stack)->n = quotient;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * mul_nodes - finds the product between the first two nodes
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

void mul_nodes(stack_t **stack, unsigned int line_num)
{
int product;

if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
exit(EXIT_FAILURE);
}
*stack = (*stack)->next;
product = (*stack)->n * (*stack)->prev->n;
(*stack)->n = product;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * mod_nodes - finds the modulus between the top two nodes
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */
void mod_nodes(stack_t **stack, unsigned int line_num)
{
int result;

if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
exit(EXIT_FAILURE);
}
*stack = (*stack)->next;
if ((*stack)->prev->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_num);
exit(EXIT_FAILURE);
}
result = (*stack)->n % (*stack)->prev->n;
(*stack)->n = result;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * pchar_node - prints the character at the top of stack
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */
void pchar_node(stack_t **stack, unsigned int line_num)
{
if (stack == NULL || (*stack) == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
exit(EXIT_FAILURE);
}
if ((*stack)-> n > 122 || (*stack)->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
exit(EXIT_FAILURE);
}
printf("%c\n", (char)(*stack)->n);
}
