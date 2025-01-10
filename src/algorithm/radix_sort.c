#include "../../push_swap.h"

void	ft_sort_tab(int *tab, int size)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (i < size -1)
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
    size = ft_stack_size(*a);
    i = 0;
    while (current != NULL)
    {
        tab[i] = current->value;
        ft_printf("Valor copiado para tab[%d]: %d\n", i, tab[i]);
        current = current->next;
        i++;
    }
    ft_sort_tab(tab, size);

    ft_printf("Array ordenado: ");
	for (i = 0; i < size; i++)
		ft_printf("%d ", tab[i]);
	ft_printf("\n");
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
                ft_printf("Valor %d recebe índice %d\n", current->value, i);
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
    int *tab;

    size = ft_stack_size(*a);
    tab = (int *)malloc(sizeof(int) * size);
    if(!tab)
        return ;
    ft_put_index(a, tab);
    free(tab);
    i = 0;
    while (i < 32) 
    {
        j = 0;
        while (j < size) 
        {
            head_a = *a;
            ft_printf("Analisando índice: %d, bit %d: %d\n", head_a->index, i, (head_a->index >> i) & 0x1);
            if ((head_a->index >> i) & 1)
            {
                ft_ra(a);
                ft_printf("Rotacionando: %d\n", head_a->value);
            } 
            else
            {
                ft_pb(a, b);
                ft_printf("Movendo para B: %d\n", head_a->value);
            }
            j++;
        }
        while (ft_stack_size(*b) > 0)
        {
            ft_printf("Movendo de volta para A: %d\n", (*b)->value);
            ft_pa(b, a);
        }
        i++;
    }
}
