#include "../../push_swap.h"

void current_index(t_stack *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = ft_stack_size(stack) / 2;
    while (stack != NULL)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = TRUE;
        else
            stack->above_median = FALSE;
        stack = stack->next;
        i++;
    }
}
void set_target_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current_b;
    t_stack *target_node;
    long best_match;

    while (stack_a != NULL)
    {
        best_match = -9223372036854775808;
        current_b = stack_b;
        while (current_b != NULL)
        {
            if (current_b->value < stack_a->value && current_b->value > best_match)
            {
                best_match = current_b->value;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match == -9223372036854775808)
        {
            stack_a->target_node = find_max(stack_b); 
        }
        else
            stack_a->target_node = target_node;
        stack_a = stack_a->next;
    }

}

void analysis_costs(t_stack *stack_a, t_stack *stack_b)
{
    int len_stack_a;
    int len_stack_b;

    len_stack_a = ft_stack_size(stack_a);
    len_stack_b = ft_stack_size(stack_b);

    while(stack_a != NULL)
    {
        stack_a->push_cost = stack_a->index;
        if (!stack_a->above_median)
            stack_a->push_cost = len_stack_a - (stack_a->index);
        if (stack_a->target_node->above_median)
            stack_a->push_cost += stack_a->target_node->index;
    }

}
t_stack *turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
    int len_stack_a;

    len_stack_a = ft_stack_size(*stack_a);
    if (len_stack_a > 3 && !ft_stack_sorted(*stack_a))
    {
        len_stack_a--;
        ft_pb(stack_b, stack_a);
    }
    if (len_stack_a > 3 && !ft_stack_sorted(*stack_a))
    {
        len_stack_a--;
        ft_pb(stack_b, stack_a);
    }
    while (len_stack < 3 && !ft_stack_sorted(*stack_a))
    {

    }
}