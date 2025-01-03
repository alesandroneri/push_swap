#include "../../push_swap.h"


// Função para deslocar todos os elementos da lista uma posição para baixo (reverse rotate)
// Essa função é usada em operações como rra e rrb no contexto do push_swap.
int ft_reverse_rotate_lst(t_stack **stack)
{
    t_stack *head; // Aponta para o início da lista (primeiro elemento).
    t_stack *tail; // Aponta para o final da lista (último elemento).

    // Verifica se há pelo menos dois elementos na stack
    if (ft_stack_size(*stack) < 2)
        return (-1);
    head = *stack;// Inicializa `head` com o início da lista.
    // Percorre a lista até encontrar o penúltimo elemento.
    // O objetivo é localizar o nó cuja próxima referência é o último nó.
    while (head != NULL)
    {
        // Verifica se o próximo nó é o penúltimo (último nó será o `head->next`).
        if (head->next->next == NULL)
        {
            // Remove a referência ao último nó, transformando o penúltimo no novo último nó.
            head->next = NULL;
            break;
        }
        // Avança para o próximo nó da lista.
        head = head->next;
    }
    tail->next = *stack;// Faz o antigo último elemento tail apontar para o início atual da lista.
    *stack = tail;// Atualiza o início da lista para que o último elemento se torne o novo início.
    return (0);
}


// Desloca todos os elementos da stack_a uma posição para baixo | Comando 'rra'
int ft_rra(t_stack **stack_a)
{
    if (ft_reverse_rotate_lst(stack_a) == -1)
        return (-1);
    ft_printf("rra\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca todos os elementos da stack_b uma posição para baixo | Comando 'rrb'
int ft_rrb(t_stack **stack_b)
{
    if (ft_reverse_rotate_lst(stack_b) == -1)
        return (-1);
    ft_printf("rrb\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca simultaneamente as stacks_a e stack_b uma posição para baixo | Comando 'rrr'
int ft_rrr(t_list **stack_a, t_list **stack_b)
{
    if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
        return (-1);
    ft_reverse_rotate_lst(stack_a);
    ft_reverse_rotate_lst(stack_b);
    ft_printf("rrr\n"); // Imprime o comando correspondente
    return (0);
}
