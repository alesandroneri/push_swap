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

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (0);
    if (ac == 2)
    {
        ft_check_arguments(ac, av);
        av = ft_split(av[1], ' ');
    }
    init_stack_a(&a, av + 1);
    if (!ft_stack_sorted(a))
    {
        if (ft_stack_size(a) == 2)
            ft_sa(&a);
        else if (ft_stack_size(a) == 3)
            sort_three(&a);
        else
           hex_radix_sort(&a, &b);
    }
    return (0);
}