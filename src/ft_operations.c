#include "../push_swap.h"

// Troca os dois primeiros elementos de uma stack | Implementa 'sa' e 'sb'
int ft_swap_lst(t_list **stack)
{
    t_list *head;      // Aponta para o primeiro elemento da stack
    t_list *next;      // Aponta para o segundo elemento da stack
    int temp_value;    // Armazena temporariamente o valor para realizar a troca
    int temp_index;    // Armazena temporariamente o índice para realizar a troca

    // Verifica se há pelo menos dois elementos na stack
    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;    // Obtém o primeiro elemento
    next = head->next; // Obtém o segundo elemento

    // Verifica se os ponteiros head e next são válidos
    if (!head && !next)
        ft_printf("Error\n");

    // Troca os valores e índices dos dois primeiros nós
    temp_value = head->value;
    temp_index = head->index;
    head->value = next->value;
    head->index = next->index;
    next->value = temp_value;
    next->index = temp_index;
    return (0);
}

// Troca os dois primeiros elementos da stack_a | Comando 'sa'
int ft_sa(t_list **stack_a)
{
    // Chama ft_swap_lst para realizar a troca
    if (ft_swap_lst(stack_a) == -1)
        return (-1);
    ft_printf("sa\n"); // Imprime o comando correspondente
    return (0);
}

// Troca os dois primeiros elementos da stack_b | Comando 'sb'
int ft_sb(t_list **stack_b)
{
    // Chama ft_swap_lst para realizar a troca
    if (ft_swap_lst(stack_b) == -1)
        return (-1);
    ft_printf("sb\n"); // Imprime o comando correspondente
    return (0);
}

// Troca simultaneamente os dois primeiros elementos das stacks_a e stack_b | Comando 'ss'
int ft_ss(t_list **stack_a, t_list **stack_b)
{
    // Verifica se ambas as stacks têm pelo menos dois elementos
    if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
        return (-1);

    // Realiza a troca em ambas as stacks
    ft_swap_lst(stack_a);
    ft_swap_lst(stack_b);
    ft_printf("ss\n"); // Imprime o comando correspondente
    return (0);
}

// Move o primeiro elemento de uma stack para o topo de outra stack | Implementa 'pa' e 'pb'
int ft_push_lst(t_list **stack_from, t_list **stack_to)
{
    t_list *temp;     // Armazena temporariamente o elemento a ser movido
    t_list *head_to;  // Cabeça da stack de destino
    t_list *head_from;// Cabeça da stack de origem

    // Verifica se a stack de origem não está vazia
    if (ft_lstsize(*stack_from) == 0)
        return (-1);

    head_to = *stack_to;
    head_from = *stack_from;
    temp = head_from;           // Salva o primeiro nó da stack de origem
    head_from = head_from->next; // Move a cabeça para o próximo elemento
    *stack_from = head_from;    // Atualiza a stack de origem
    // Insere o nó na stack de destino
    if (!head_to)
    {
        head_to = temp;
        head_to->next = NULL;
        *stack_to = head_to;
    }
    else
    {
        temp->next = head_to;
        *stack_to = temp;
    }
    return (0);
}

// Move o primeiro elemento da stack_b para a stack_a | Comando 'pa'
int ft_pa(t_list **stack_b, t_list **stack_a)
{
    if (ft_push_lst(stack_b, stack_a) == -1)
        return (-1);
    ft_printf("pa\n"); // Imprime o comando correspondente
    return (0);
}

// Move o primeiro elemento da stack_a para a stack_b | Comando 'pb'
int ft_pb(t_list **stack_a, t_list **stack_b)
{
    if (ft_push_lst(stack_a, stack_b) == -1)
        return (-1);
    ft_printf("pb\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca todos os elementos da stack uma posição para cima | Implementa 'ra' e 'rb'
int ft_rotate_lst(t_list **stack)
{
    t_list *head;  // Aponta para o primeiro elemento
    t_list *tail;  // Aponta para o último elemento

    // Verifica se há pelo menos dois elementos na stack
    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(*stack);
    *stack = head->next; // Move a cabeça para o próximo elemento
    head->next = NULL;   // Remove o vínculo do antigo head
    tail->next = head;   // Coloca o antigo head como o último elemento
    return (0);
}

// Desloca todos os elementos da stack_a uma posição para cima | Comando 'ra'
int ft_ra(t_list **stack_a)
{
    if (ft_rotate_lst(stack_a) == -1)
        return (-1);
    ft_printf("ra\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca todos os elementos da stack_b uma posição para cima | Comando 'rb'
int ft_rb(t_list **stack_b)
{
    if (ft_rotate_lst(stack_b) == -1)
        return (-1);
    ft_printf("rb\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca simultaneamente as stacks_a e stack_b uma posição para cima | Comando 'rr'
int ft_rr(t_list **stack_a, t_list **stack_b)
{
    if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
        return (-1);
    ft_rotate_lst(stack_a);
    ft_rotate_lst(stack_b);
    ft_printf("rr\n"); // Imprime o comando correspondente
    return (0);
}

// Função para deslocar todos os elementos da lista uma posição para baixo (reverse rotate)
// Essa função é usada em operações como rra e rrb no contexto do push_swap.
int ft_reverse_rotate_lst(t_list **stack)
{
    t_list *head; // Aponta para o início da lista (primeiro elemento).
    t_list *tail; // Aponta para o final da lista (último elemento).

    // Verifica se há pelo menos dois elementos na stack
    if (ft_lstsize(*stack) < 2)
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
int ft_rra(t_list **stack_a)
{
    if (ft_reverse_rotate_lst(stack_a) == -1)
        return (-1);
    ft_printf("rra\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca todos os elementos da stack_b uma posição para baixo | Comando 'rrb'
int ft_rrb(t_list **stack_b)
{
    if (ft_reverse_rotate_lst(stack_b) == -1)
        return (-1);
    ft_printf("rrb\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca simultaneamente as stacks_a e stack_b uma posição para baixo | Comando 'rrr'
int ft_rrr(t_list **stack_a, t_list **stack_b)
{
    if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
        return (-1);
    ft_reverse_rotate_lst(stack_a);
    ft_reverse_rotate_lst(stack_b);
    ft_printf("rrr\n"); // Imprime o comando correspondente
    return (0);
}

