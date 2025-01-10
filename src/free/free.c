#include "../../push_swap.h"

void ft_free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}
void ft_free_split(char **strs)
{
    int i;

    i = 0;
    while (strs[i] != NULL)
    {
        free(strs[i]);
        i++;
    }
    free(strs);
}