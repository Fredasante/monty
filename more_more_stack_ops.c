#include "monty.h"

/**
 * pstr_nodes - prints the string starting at the top of the stack
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

void pstr_nodes(stack_t **stack, unsigned int line_num)
{
stack_t *temp;
(void) line_num;
temp = *stack;
if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}
while (temp != NULL)
{
if (temp->n > 122 || temp->n <= 0)
break;
printf("%c", temp->n);
temp = temp->next;
}
printf("\n");
}

/**
 * rotate_top - rotates the stack to the top
 * @stack: double pointer to top of stack
 * @line_num: line number of opcode
 */

void rotate_top(stack_t **stack, unsigned int line_num)
{
stack_t *bottom;
(void) line_num;
bottom = *stack;
if (!stack || !(*stack) || !((*stack)->next))
return;
while (bottom->next)
{
bottom = bottom->next;
}
bottom->next = *stack;
(*stack)->prev = bottom;
(*stack) = (*stack)->next;
(*stack)->prev->next = NULL;
(*stack)->prev = NULL;
}

/**
 * rotate_bottom - rotates the stack to the bottom
 * @stack: double pointer to top of stack
 * @line_num: lin number of opcode
 */
void rotate_bottom(stack_t **stack, unsigned int line_num)
{
stack_t *bottom;
(void) line_num;
bottom = *stack;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
return;
while (bottom->next != NULL)
{
bottom = bottom->next;
}
bottom->next = *stack;
(*stack)->prev = bottom;
bottom->prev->next = NULL;
bottom->prev = NULL;
*stack = bottom;
}
