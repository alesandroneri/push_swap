/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_operations_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:28:16 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/15 14:28:22 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_reverse_rotate_lst(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stack_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_stack_last(*stack);
	while (head != NULL)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	(*stack)->prev = tail;
	*stack = tail;
	return (0);
}

int	ft_rra(t_stack **stack_a)
{
	if (ft_reverse_rotate_lst(stack_a) == -1)
		return (-1);
	ft_printf("rra\n");
	return (0);
}

int	ft_rrb(t_stack **stack_b)
{
	if (ft_reverse_rotate_lst(stack_b) == -1)
		return (-1);
	ft_printf("rrb\n");
	return (0);
}

int	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
		return (-1);
	ft_reverse_rotate_lst(stack_a);
	ft_reverse_rotate_lst(stack_b);
	ft_printf("rrr\n");
	return (0);
}
