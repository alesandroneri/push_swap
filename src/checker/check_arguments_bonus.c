#include "checker_bonus.h"

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

	if (!nb)
	  	return (0);
	if (ft_strlen(nb) == 1 && (nb[0] == '-' || nb[0] == '+'))
		return (0);
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

int ft_count_split(char **split_args)
{
    int count = 0;

    while (split_args[count])
        count++;
    return (count);
}

int ft_check_arguments(int ac, char **av)
{
    int i;
	int j;
    long nb;

    i = 0;
    while (i < ac)
    {
		if (av[i][0] == '\0')
			return (0);
        if (!ft_is_all_numbers(av[i])) // Verifica se cada argumento é um número.
            return (0);
        nb = ft_atol(av[i]); // Converte para long para verificar range.
        if (!ft_is_int(nb)) // Verifica se está dentro do intervalo de int.
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
