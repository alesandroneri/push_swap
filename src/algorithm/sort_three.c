/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:30:55 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/17 15:18:14 by aneri-da         ###   ########.fr       */
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
