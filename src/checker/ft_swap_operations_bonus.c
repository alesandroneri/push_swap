/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:25:57 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/15 15:13:57 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_swap_lst(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;

	if (ft_stack_size(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	head->next = next->next;
	if (next->next)
		next->next->prev = head;
	next->prev = NULL;
	next->next = head;
	*stack = next;
	return (0);
}
int	ft_sa(t_stack **stack_a)
{
	if (ft_swap_lst(stack_a) == -1)
		return (-1);
	ft_printf("sa\n");
	return (0);
}

int	ft_sb(t_stack **stack_b)
{
	if (ft_swap_lst(stack_b) == -1)
		return (-1);
	ft_printf("sb\n");
	return (0);
}

int	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return (-1);
	ft_swap_lst(stack_a);
	ft_swap_lst(stack_b);
	ft_printf("ss\n");
	return (0);
}