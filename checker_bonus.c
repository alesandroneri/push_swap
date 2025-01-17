/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:17:46 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/17 14:36:24 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker_bonus.h"

int valid_arguments2(int ac, char **av, t_stack **stack_a)
{
	char **split_args;
	int i;
	
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

int valid_arguments(int ac, char **av, t_stack **stack_a)
{
	int i;

	i = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	while (av[i])
		if (av[i++][0] == '\0')
		{
			ft_putendl_fd("Error", 2);
			return (0);
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

int	read_operations(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
		return (ft_swap_lst(stack_a), 0);
	if (!ft_strcmp(line, "sb\n"))
		return (ft_swap_lst(stack_b), 0);
	if (!ft_strcmp(line, "ss\n"))
	{
		ft_swap_lst(stack_a);
		ft_swap_lst(stack_b);
		return (0);
	}
	if (!ft_strcmp(line, "pa\n"))
		return (ft_push_lst(stack_b, stack_a), 0);
	if (!ft_strcmp(line, "pb\n"))
		return (ft_push_lst(stack_a, stack_b), 0);
	if (!ft_strcmp(line, "ra\n"))
		return (ft_rotate_lst(stack_a), 0);
	if (!ft_strcmp(line, "rb\n"))
		return (ft_rotate_lst(stack_b), 0);
	if (!ft_strcmp(line, "rr\n"))
	{
		ft_rotate_lst(stack_a);
		ft_rotate_lst(stack_b);
		return (0);
	}
	if (!ft_strcmp(line, "rra\n"))
		return (ft_reverse_rotate_lst(stack_a), 0);
	if (!ft_strcmp(line, "rrb\n"))
		return (ft_reverse_rotate_lst(stack_b), 0);
	if (!ft_strcmp(line, "rrr\n"))
	{
		ft_reverse_rotate_lst(stack_a);
		ft_reverse_rotate_lst(stack_b);
		return (0);
	}
	return (1);
}
void	print_message(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_sorted(*stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (*stack_a)
		ft_free_stack(stack_a);
	if (*stack_b)
		ft_free_stack(stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (!valid_arguments(ac, av, &a))
		return (0);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (read_operations(line, &a, &b))
		{
			free(line);
			get_next_line(EOF);
			ft_free_stack(&a);
			ft_free_stack(&b);
			ft_putendl_fd("Error", 2);
			return (close(EOF), 0);
		}
		free(line);
		line = get_next_line(0);
	}
	print_message(&a, &b);
	return (0);
}
