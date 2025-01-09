#include "../../push_swap.h"
#include <stdio.h>

int ft_stack_size(t_stack *stack)
{
    int count;

    if (!stack)
        return (0);
    count = 0;
    while (stack != NULL)
    {
        count++;
        stack = stack->next;
    }
    return (count);
}

t_stack *ft_stack_last(t_stack *stack)
{
    t_stack *last;

    if (!stack)
        return (NULL);
    last = stack;
    while (last->next != NULL)
        last = last->next;
    return (last);
}

int ft_stack_sorted(t_stack *stack)
{
    if (!stack)
        return (0);
    while (stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (FALSE);
        stack = stack->next;
    }
    return (TRUE);
}
void init_stack_a(t_stack **a, char **av)
{
    int i;
    long n;

    i = 0;
    while (av[i])
    {
        n = ft_atol(av[i]);
        if (n < -2147483648 || n > 2147483647)
        {
            ft_putendl_fd("Error", 2);
            return ;
        }
        fill_stack(a, n);
        i++;
    }
}

void fill_stack(t_stack **stack, int n)
{
    t_stack *last_node;
    t_stack *node;

    if (!stack)
        return ;
    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->next = NULL;
    node->value = n;
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = ft_stack_last(*stack);
        last_node->next = node;
        node->prev = last_node; 
    }
}

void ft_print_stack(t_stack *stack)
{
    if (!stack)
        return ;
    while (stack != NULL)
    {
        ft_printf("%d ", stack->value);
        stack = stack->next;
    }
}
