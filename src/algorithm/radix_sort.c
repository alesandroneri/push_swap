#include "../../push_swap.h"

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (i <= size - 2)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

void ft_put_index(t_stack **a, int *tab)
{
    int i;

    i = 0;
    while (a != NULL)
    {
        tab[i] = (*a)->value;
        a = (*a)->next;
        i++;
    }
    ft_sort_tab(tab, ft_stack_size(*a));

}

void hex_radix_sort(t_stack **a, t_stack **b) 
{
    int i;
    int j;
    int size;
    t_stack *head_a;

    size = ft_stack_size(*a);
    i = 0;
    while (i < 8) 
    {
        j = 0;
        while (j < size) 
        {
            head_a = *a;
            if (head_a->index >> (4 * i) & 0xF)
                ft_ra(a);
            else 
                ft_pb(b, a);
            j++;
        }
        while (ft_stack_size(*a) != 0)
            ft_pa(a, b);
        i++;
    }
}
