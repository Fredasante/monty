#include "monty.h"

/**
 * do_nothing - does nothing
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */
void do_nothing(stack_t **stack, unsigned int line_num)
{
(void)stack;
(void)line_num;
}

/**
 * swap_nodes - swaps the top two stack nodes
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

void swap_nodes(stack_t **stack, unsigned int line_num)
{
stack_t *temp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
exit(EXIT_FAILURE);
}
temp = (*stack)->next;
(*stack)->next = temp->next;
if (temp->next != NULL)
temp->next->prev = *stack;
temp->next = *stack;
(*stack)->prev = temp;
temp->prev = NULL;
*stack = temp;
}

/**
 * sum_nodes - finds the sum of the top two elements
 * @stack: double pointer to top of stack
 * @line_num: line number of stack
 */

void sum_nodes(stack_t **stack, unsigned int line_num)
{
int sum;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
exit(EXIT_FAILURE);
}
(*stack) = (*stack)->next;
sum = (*stack)->n + (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * sub_nodes - finds the difference between the first two nodes
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */
void sub_nodes(stack_t **stack, unsigned int line_num)
{
int diff;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
exit(EXIT_FAILURE);
}
*stack = (*stack)->next;
diff = (*stack)->n - (*stack)->prev->n;
(*stack)->n = diff;
free((*stack)->prev);
(*stack)->prev = NULL;
}
