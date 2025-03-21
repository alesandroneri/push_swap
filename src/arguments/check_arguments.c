/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:14:28 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/17 14:37:26 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_int(long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}

int	ft_is_all_numbers(char *nb)
{
	int	i;

	if (!nb)
		return (0);
	if (ft_strlen(nb) == 1 && (nb[0] == '-' || nb[0] == '+'))
		return (0);
	i = 0;
	if (nb[0] == '-' || nb[0] == '+')
		i++;
	while (nb[i] != '\0')
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_split(char **split_args)
{
	int	count;

	count = 0;
	while (split_args[count])
		count++;
	return (count);
}

int	ft_check_arguments(int ac, char **av)
{
	int		i;
	int		j;
	long	nb;

	i = 0;
	while (i < ac)
	{
		if (!ft_is_all_numbers(av[i]))
			return (0);
		nb = ft_atol(av[i]);
		if (!ft_is_int(nb))
			return (0);
		j = i + 1;
		while (av[j] != NULL)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
