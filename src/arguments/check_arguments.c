#include "../../push_swap.h"

//Verificar se o numero esta dentro do range dos numeros inteiros.
int ft_is_int(long nb, char **av, int i)
{
    while (av[i])
    {
        if (ft_atol(av[i]) == nb)
            return (1);
        i++;
    }
    return (0);
}
//Verificar se e um numero valido seja negativo/positivo.
int ft_is_all_numbers(char *nb)
{
    int i;

    i = 0;
    if (nb[0] == '-' || nb[0] == '+')//Verificacao de sinal.
        i++;
    while (nb[i] != '\0')
    {
        if (!ft_isdigit(nb[i]))//Verificando se ha somente numeros ou se ha somente numeros apos o sinal.
            return (0);
        i++;
    }
    return (1);
}
//Verificacao de argumentos caso sejam passados como uma unica string ou se forem passados como argumentos separados.
void    ft_check_arguments(int ac, char **av)
{
    int i;
    long nb;
    
    i = 1;
    if (ac == 2)
        ft_split(av[1], ' ');
    while (av[i] != NULL)
    {
        if (!ft_is_all_numbers(av[i]))// retornar mensagem de error.
            ft_putendl_fd("Error", 2);
        if ((nb = ft_atol(av[i]) > 2147483647) || (nb = ft_atol(av[i]) < -2147483648))
            ft_putendl_fd("Error", 2);
        i++;
    }
}