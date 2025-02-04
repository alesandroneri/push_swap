/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:23:06 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 13:52:35 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*ft_stack_last(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	fill_stack(t_stack **stack, int n)
{
	t_stack	*last_node;
	t_stack	*node;

	if (!stack)
		return ;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_stack_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack **a, char **av)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		n = ft_atol(av[i]);
		if (n < (long)-2147483648 || n > (long)2147483647)
		{
			ft_putendl_fd("Error", 2);
			return ;
		}
		fill_stack(a, n);
		i++;
	}
}

void	ft_print_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack != NULL)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
}
