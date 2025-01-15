/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:20:08 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/15 15:46:03 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <limits.h>

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	long	min;

	if (!stack)
		return (NULL);
	//min = LONG_MAX;
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
	//max = LONG_MIN;
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
