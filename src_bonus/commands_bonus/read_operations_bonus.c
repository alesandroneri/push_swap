/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:31:56 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 13:59:53 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

int	read_operations2(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
	{
		ft_swap_lst(stack_a);
		return (0);
	}
	if (!ft_strcmp(line, "sb\n"))
	{
		ft_swap_lst(stack_b);
		return (0);
	}
	if (!ft_strcmp(line, "ss\n"))
	{
		ft_swap_lst(stack_a);
		ft_swap_lst(stack_b);
		return (0);
	}
	if (!ft_strcmp(line, "pa\n"))
	{
		ft_push_lst(stack_b, stack_a);
		return (0);
	}
	return (1);
}

int	read_operations3(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "pb\n"))
	{
		ft_push_lst(stack_a, stack_b);
		return (0);
	}
	if (!ft_strcmp(line, "ra\n"))
	{
		ft_rotate_lst(stack_a);
		return (0);
	}
	if (!ft_strcmp(line, "rb\n"))
	{
		ft_rotate_lst(stack_b);
		return (0);
	}
	if (!ft_strcmp(line, "rr\n"))
	{
		ft_rotate_lst(stack_a);
		ft_rotate_lst(stack_b);
		return (0);
	}
	return (1);
}

int	read_operations(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!read_operations2(line, stack_a, stack_b))
		return (0);
	if (!read_operations3(line, stack_a, stack_b))
		return (0);
	if (!ft_strcmp(line, "rra\n"))
	{
		ft_reverse_rotate_lst(stack_a);
		return (0);
	}
	if (!ft_strcmp(line, "rrb\n"))
	{
		ft_reverse_rotate_lst(stack_b);
		return (0);
	}
	if (!ft_strcmp(line, "rrr\n"))
	{
		ft_reverse_rotate_lst(stack_a);
		ft_reverse_rotate_lst(stack_b);
		return (0);
	}
	return (1);
}
