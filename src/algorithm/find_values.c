#include "../../push_swap.h"
#include <limits.h>
// Função para encontrar o menor valor da pilha
t_stack *find_min(t_stack *stack)
{
    t_stack *min_node;
    long    min;

    if (!stack)
        return (NULL);
    //min = 9223372036854775807;
    min = LONG_MAX;
    while (stack != NULL)
    {
        if (stack->value < min)
        {
            min = stack->value;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}
// Função para encontrar o maior valor da pilha
t_stack *find_max(t_stack *stack)
{
    t_stack *max_node;
    long max;

    if (!stack)
        return (NULL);
    //max = -9223372036854775808;
    max = LONG_MIN;
    while (stack != NULL)
    {
        if (stack->value > max)
        {
            max = stack->value;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}
