/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:59:51 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/17 15:12:53 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

int	ft_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_check_dup_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (checker->value == current->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	long	min;

	if (!stack)
		return (NULL);
    min = 9223372036854775807;
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	long	max;

	if (!stack)
		return (NULL);
    max = -9223372036854775807-1;
	while (stack != NULL)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
