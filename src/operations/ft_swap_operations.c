#include "../../push_swap.h"

// Troca os dois primeiros elementos de uma stack | Implementa 'sa' e 'sb'
int ft_swap_lst(t_stack **stack)
{
    t_stack *head;      // Aponta para o primeiro elemento da stack
    t_stack *next;      // Aponta para o segundo elemento da stack
    int temp_value;    // Armazena temporariamente o valor para realizar a troca
    int temp_index;    // Armazena temporariamente o índice para realizar a troca

    // Verifica se há pelo menos dois elementos na stack
    if (ft_stack_size(*stack) < 2)
        return (-1);
    head = *stack;    // Obtém o primeiro elemento
    next = head->next; // Obtém o segundo elemento

    // Verifica se os ponteiros head e next são válidos
    if (!head && !next)
        ft_putendl_fd("Error", 2);
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
int ft_sa(t_stack **stack_a)
{
    // Chama ft_swap_lst para realizar a troca
    if (ft_swap_lst(stack_a) == -1)
        return (-1);
    ft_printf("sa\n"); // Imprime o comando correspondente
    return (0);
}

// Troca os dois primeiros elementos da stack_b | Comando 'sb'
int ft_sb(t_stack **stack_b)
{
    // Chama ft_swap_lst para realizar a troca
    if (ft_swap_lst(stack_b) == -1)
        return (-1);
    ft_printf("sb\n"); // Imprime o comando correspondente
    return (0);
}

// Troca simultaneamente os dois primeiros elementos das stacks_a e stack_b | Comando 'ss'
int ft_ss(t_stack **stack_a, t_list **stack_b)
{
    // Verifica se ambas as stacks têm pelo menos dois elementos
    if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
        return (-1);

    // Realiza a troca em ambas as stacks
    ft_swap_lst(stack_a);
    ft_swap_lst(stack_b);
    ft_printf("ss\n"); // Imprime o comando correspondente
    return (0);
}