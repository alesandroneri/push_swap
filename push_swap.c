/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:50:33 by aneri-da          #+#    #+#             */
/*   Updated: 2024/12/06 10:50:35 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_stack_sorted(*stack_a))
	{
		if (ft_stack_size(*stack_a) == 2)
			ft_sa(stack_a);
		else if (ft_stack_size(*stack_a) == 3)
			sort_three(stack_a);
		else
			radix(stack_a, stack_b);
	}
}
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_args;
	int		i;
	int		j;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	i = 0;
	while (++i < ac)
	{
		split_args = ft_split(av[i], ' ');
		if (!split_args)
			return (ft_putendl_fd("Error", 2), 0);
		if (!ft_check_arguments(ft_count_split(split_args), split_args))
		{
			ft_free_split(split_args);
			ft_free_stack(&a);
			return (ft_putendl_fd("Error", 2), 0);
		}
		j = i + 1;
		while (av[j] != NULL)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{
				if (split_args)
					ft_free_split(split_args);
				ft_free_stack(&a);
				return (ft_putendl_fd("Error", 2), 0);
			}
			j++;
		}
		init_stack_a(&a, split_args);
		ft_free_split(split_args);
	}
	sort_stack(&a, &b);
	// ft_print_stack(a);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
