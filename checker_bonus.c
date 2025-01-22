/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:17:46 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 13:41:32 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker_bonus.h"

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
			get_next_line(3);
			ft_free_stacks(&a, &b);
			ft_putendl_fd("Error", 2);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	print_message(&a, &b);
	return (0);
}
