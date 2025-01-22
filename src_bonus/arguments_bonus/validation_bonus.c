/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:28:38 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 13:59:01 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

int	valid_arguments2(int ac, char **av, t_stack **stack_a)
{
	char	**split_args;
	int		i;

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

int	valid_arguments(int ac, char **av, t_stack **stack_a)
{
	int	i;

	i = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		i++;
	}
	if (!valid_arguments2(ac, av, stack_a))
		return (0);
	if (ft_check_dup_stack(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_putendl_fd("Error", 2);
		return (0);
	}
	return (1);
}
