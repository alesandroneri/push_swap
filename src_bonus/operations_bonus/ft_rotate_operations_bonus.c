/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_operations_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:26:45 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 14:00:50 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

int	ft_rotate_lst(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stack_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_stack_last(*stack);
	*stack = head->next;
	head->next = NULL;
	head->prev = tail;
	tail->next = head;
	return (0);
}

int	ft_ra(t_stack **stack_a)
{
	if (ft_rotate_lst(stack_a) == -1)
		return (-1);
	ft_printf("ra\n");
	return (0);
}

int	ft_rb(t_stack **stack_b)
{
	if (ft_rotate_lst(stack_b) == -1)
		return (-1);
	ft_printf("rb\n");
	return (0);
}

int	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return (-1);
	ft_rotate_lst(stack_a);
	ft_rotate_lst(stack_b);
	ft_printf("rr\n");
	return (0);
}
