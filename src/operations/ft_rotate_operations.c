#include "../../push_swap.h"

// Desloca todos os elementos da stack uma posição para cima | Implementa 'ra' e 'rb'
int ft_rotate_lst(t_stack **stack)
{
    t_stack *head;  // Aponta para o primeiro elemento
    t_stack *tail;  // Aponta para o último elemento

    // Verifica se há pelo menos dois elementos na stack
    if (ft_stack_size(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_stack_last(*stack);
    *stack = head->next; // Move a cabeça para o próximo elemento
    head->next = NULL;   // Remove o vínculo do antigo head
    head->prev = tail;   // O antigo head agora aponta para o antigo tail
    tail->next = head;   // Coloca o antigo head como o último elemento
    return (0);
}

// Desloca todos os elementos da stack_a uma posição para cima | Comando 'ra'
int ft_ra(t_stack **stack_a)
{
    if (ft_rotate_lst(stack_a) == -1)
        return (-1);
    ft_printf("ra\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca todos os elementos da stack_b uma posição para cima | Comando 'rb'
int ft_rb(t_stack **stack_b)
{
    if (ft_rotate_lst(stack_b) == -1)
        return (-1);
    ft_printf("rb\n"); // Imprime o comando correspondente
    return (0);
}

// Desloca simultaneamente as stacks_a e stack_b uma posição para cima | Comando 'rr'
int ft_rr(t_stack **stack_a, t_stack **stack_b)
{
    if ((ft_stack_size(*stack_a) < 2) || (ft_stack_size(*stack_b) < 2))
        return (-1);
    ft_rotate_lst(stack_a);
    ft_rotate_lst(stack_b);
    ft_printf("rr\n"); // Imprime o comando correspondente
    return (0);
}