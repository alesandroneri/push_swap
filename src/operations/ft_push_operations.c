/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:24:41 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 13:51:56 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_push_lst(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*temp;
	t_stack	*head_to;
	t_stack	*head_from;

	if (ft_stack_size(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	temp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		head_to->prev = NULL;
		*stack_to = head_to;
		return (0);
	}
	temp->next = head_to;
	head_to->prev = temp;
	temp->prev = NULL;
	*stack_to = temp;
	return (0);
}

int	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	if (ft_push_lst(stack_b, stack_a) == -1)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push_lst(stack_a, stack_b) == -1)
		return (-1);
	ft_printf("pb\n");
	return (0);
}
