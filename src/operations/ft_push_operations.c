#include "../../push_swap.h"

// Move o primeiro elemento de uma stack para o topo de outra stack | Implementa 'pa' e 'pb'
int ft_push_lst(t_stack **stack_from, t_stack **stack_to)
{
    t_stack *temp;      // Armazena temporariamente o elemento a ser movido
    t_stack *head_to;   // Cabeça da stack de destino
    t_stack *head_from; // Cabeça da stack de origem

    // Verifica se a stack de origem não está vazia
    if (ft_lstsize(*stack_from) == 0)
        return (-1);
    head_to = *stack_to;
    head_from = *stack_from;
    temp = head_from;            // Salva o primeiro nó da stack de origem
    head_from = head_from->next; // Move a cabeça para o próximo elemento
    *stack_from = head_from;     // Atualiza a stack de origem
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
int ft_pa(t_stack **stack_b, t_stack **stack_a)
{
    if (ft_push_lst(stack_b, stack_a) == -1)
        return (-1);
    ft_printf("pa\n"); // Imprime o comando correspondente
    return (0);
}

// Move o primeiro elemento da stack_a para a stack_b | Comando 'pb'
int ft_pb(t_stack **stack_a, t_stack **stack_b)
{
    if (ft_push_lst(stack_a, stack_b) == -1)
        return (-1);
    ft_printf("pb\n"); // Imprime o comando correspondente
    return (0);
}