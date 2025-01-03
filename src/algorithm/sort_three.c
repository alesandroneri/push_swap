#include "../../push_swap.h"

void sort_three(t_stack **stack_a)
{
    t_stack *biggest_node;

    biggest_node = find_max(*stack_a);
    if (biggest_node == *stack_a)
        ft_ra(stack_a);
    if ((*stack_a)->next == biggest_node)
        ft_rra(stack_a);
    if ((*stack_a)->value > (*stack_a)->next->value)
        ft_sa(stack_a);
}