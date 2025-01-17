/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:31:08 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/17 15:57:08 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

void	ft_put_index(t_stack **a, int *tab)
{
	int		i;
	int		size;
	t_stack	*current;

	current = *a;
	size = ft_stack_size(*a);
	i = -1;
	while (current != NULL)
	{
		tab[++i] = current->value;
		current = current->next;
	}
	ft_sort_tab(tab, size);
	current = *a;
	while (current != NULL)
	{
		i = -1;
		while (++i < size)
		{
			if (current->value == tab[i])
				current->index = i;
		}
		current = current->next;
	}
}

void	radix_sort_b(t_stack **a, t_stack **b, int bit)
{
	int		size;
	int		i;
	t_stack	*head_b;

	size = ft_stack_size(*b);
	i = 0;
	while (i < size)
	{
		head_b = *b;
		if (((head_b->index >> bit) & 1))
			ft_rb(b);
		else
			ft_pa(b, a);
		i++;
	}
}

void	radix(t_stack **a, t_stack **b, int size, int max_bits)
{
	int		i;
	int		j;
	t_stack	*head_a;
	int		*tab;

	tab = (int *)malloc(sizeof(int) * size);
	ft_put_index(a, tab);
	free(tab);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (ft_stack_sorted(*a) && ft_stack_sorted2(*b))
				break ;
			head_a = *a;
			if (((head_a->index >> i) & 1))
				ft_ra(a);
			else
				ft_pb(a, b);
		}
		radix_sort_b(a, b, i);
	}
}
