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
    int size;
    t_stack *current;

    current = *a;
    size = 0;
    i = 0;
    while (current != NULL)
    {
        tab[i] = current->value;
        current = current->next;
        i++;
    }
    ft_sort_tab(tab, size);
    // Associar os índices ordenados de volta à pilha
    current = *a;
    while (current != NULL)
    {
        i = 0;
        while (i < size)
        {
            if (current->value == tab[i])
            {
                current->index = i; // Associar índice baseado na posição em tab
                break;
            }
            i++;
        }
        current = current->next;
    }
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
            if (head_a && head_a->index >> (4 * i) & 0xF)
                ft_ra(a);
            else 
                ft_pb(b, a);
            j++;
        }
        while (ft_stack_size(*a) != 0)
            ft_pa(b, a);
        i++;
    }
}
