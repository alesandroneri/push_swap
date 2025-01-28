/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:50:33 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/28 15:41:43 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	valid_arguments(int ac, char **av, t_stack **stack_a)
{
	char	**split_args;
	int		i;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	i = 0;
	while (++i < ac)
	{
		split_args = ft_split(av[i], ' ');
		if (!split_args)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		if (!ft_check_arguments(ft_count_split(split_args), split_args))
		{
			ft_free_split(split_args);
			ft_free_stack(stack_a);
			ft_putendl_fd("Error", 2);
			return (0);
		}
		init_stack_a(stack_a, split_args);
		ft_free_split(split_args);
	}
	return (1);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;

	if (!ft_stack_sorted(*stack_a))
	{
		if (ft_stack_size(*stack_a) == 2)
			ft_sa(stack_a);
		else if (ft_stack_size(*stack_a) == 3)
			sort_three(stack_a);
		else if (ft_stack_size(*stack_a) == 4)
			sort_four(stack_a, stack_b);
		else if (ft_stack_size(*stack_a) == 5)
			sort_five(stack_a, stack_b);
		else
		{
			max_bits = 0;
			size = ft_stack_size(*stack_a);
			while ((size - 1) >> max_bits++)
				;
			radix(stack_a, stack_b, size, max_bits);
		}
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_check_dup_stack(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_putendl_fd("Error", 2);
		return ;
	}
	sorting(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (valid_arguments(ac, av, &a) == 0)
		return (0);
	if (ft_stack_size(a) == 0)
		return (0);
	sort_stack(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
