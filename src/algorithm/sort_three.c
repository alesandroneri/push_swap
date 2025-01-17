/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:55 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/17 18:35:21 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*stack_a);
	if (biggest_node == *stack_a)
		ft_ra(stack_a);
	if ((*stack_a)->next == biggest_node)
		ft_rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_sa(stack_a);
}
void sort_four(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *smallest_node;
    
    smallest_node = find_min(*stack_a);
    while (*stack_a != smallest_node)
        ft_ra(stack_a);
    ft_pb(stack_a, stack_b);
    sort_three(stack_a);
    ft_pa(stack_b, stack_a);
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *biggest_node;

    biggest_node = find_max(*stack_a);
    while (*stack_a != biggest_node)
        ft_ra(stack_a);
    ft_pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	ft_pa(stack_b, stack_a);
	ft_ra(stack_a);
}

