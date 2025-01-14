#include "../../push_swap.h"

int commands(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if(!ft_strcmp(line, "sa"))
        return (ft_swap_lst(stack_a), 0);
    if(!ft_strcmp(line, "sb"))
        return (ft_swap_lst(stack_b), 0);
    if(!ft_strcmp(line, "ss"))
    {
        ft_swap_lst(stack_a);
        ft_swap_lst(stack_b);
        return (0);
    }
    if(!ft_strcmp(line, "pa"))
        return (ft_push_lst(stack_b, stack_a), 0);
    if(!ft_strcmp(line, "pb"))
        return (ft_push_lst(stack_a, stack_b), 0);
    if(!ft_strcmp(line, "ra"))
        return (ft_rotate_lst(stack_a), 0);
    if(!ft_strcmp(line, "rb"))
        return (ft_rotate_lst(stack_b), 0);
    if(!ft_strcmp(line, "rr"))
    {
        ft_rotate_lst(stack_a);
        ft_rotate_lst(stack_b);
        return (0);
    }
    if(!ft_strcmp(line, "rra"))
        return (ft_reverse_rotate_lst(stack_a), 0);
    if(!ft_strcmp(line, "rrb"))
        return (ft_reverse_rotate_lst(stack_b), 0);
    if(!ft_strcmp(line, "rrr"))
    {
        ft_reverse_rotate_lst(stack_a);
        ft_reverse_rotate_lst(stack_b);
        return (0);
    }
    return (1);
}
void print_message(t_stack **stack_a, t_stack **stack_b)
{
    if (ft_stack_sorted(*stack_a))
        ft_putendl_fd("OK", 1);
    else
        ft_putendl_fd("KO", 1);
    if (*stack_a)
        ft_free_stack(stack_a);
    if(*stack_b)
        ft_free_stack(stack_b);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    char **split_args;
    char *line;
    int i;

    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (0);

    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    a = NULL;
    b = NULL;
    i = 0;
    while (++i < ac)
    {
        split_args = ft_split(av[i], ' ');
        if(!split_args)
            return (ft_putendl_fd("Error", 2), 0);
        if(!ft_check_arguments(ft_count_split(split_args), split_args))
        {
            ft_free_split(split_args);
            ft_free_stack(&a);
            return (ft_putendl_fd("Error", 2), 0);
        }
        init_stack_a(&a, split_args);
        ft_free_split(split_args);
    }
    while ((line = get_next_line(0)))
    {
        if (commands(line, &a, &b))
        {
            ft_putendl_fd("Error", 2);
            return(-1);
        }
        free(line);
    }
    print_message(&a, &b);
    return (0);
}