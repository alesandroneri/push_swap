#include "../../push_swap.h"


int ft_swap_lst(t_stack **stack)
{
    t_stack *head;
    t_stack *next;
    
    // Verifica se há pelo menos dois elementos na stack
    if (ft_stack_size(*stack) < 2)
        return (-1);
    head = *stack;          // Obtém o primeiro elemento da stack
    next = head->next;      // Obtém o segundo elemento da stack
    // Troca os ponteiros entre os nós
    head->next = next->next;
    if (next->next)         // Se o próximo nó não for NULL, ajusta o ponteiro 'prev' corretamente
        next->next->prev = head;
    next->prev = NULL;
    next->next = head;      // O segundo nó passa a ser o primeiro
    *stack = next;          // A cabeça da lista é atualizada para o segundo nó
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
int ft_ss(t_stack **stack_a, t_stack **stack_b)
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