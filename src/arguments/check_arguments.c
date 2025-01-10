#include "../../push_swap.h"

// Verificar se o numero esta dentro do range dos numeros inteiros.
int	ft_is_int(long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}
// Verificar se e um numero valido seja negativo/positivo.
int	ft_is_all_numbers(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-' || nb[0] == '+') // Verificacao de sinal.
		i++;
	while (nb[i] != '\0')
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}
// Verificacao de argumentos caso sejam passados como uma unica string ou se forem passados como argumentos separados.
int	ft_check_arguments(int ac, char **av)
{
	int i;
	int j;
	long nb;
	char **split_args;

	i = 0;
	while (++i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
		split_args = ft_split(av[1], ' ');
		if (!split_args)
			return (0);
		j = 0;
		while (split_args[j])
		{
			if (!ft_is_all_numbers(split_args[j]))
			{
				ft_free_split(split_args);
				return (0);
			}
			nb = ft_atol(split_args[j]);
			if (!ft_is_int(nb))
			{
				ft_free_split(split_args);
				return (0);
			}
			j++;
		}
		ft_free_split(split_args);
		}
		else
		{
            if (!ft_is_all_numbers(av[i]))
                return (0);
            nb = ft_atol(av[i]);
            if (!ft_is_int(nb))
                return (0);
        }
	}
	return (1);
}
