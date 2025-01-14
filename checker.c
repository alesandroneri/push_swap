#include "src/checker/checker_bonus.h"

int read_operations(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if(!ft_strcmp(line, "sa\n"))
        return (ft_swap_lst(stack_a), 0);
    if(!ft_strcmp(line, "sb\n"))
        return (ft_swap_lst(stack_b), 0);
    if(!ft_strcmp(line, "ss\n"))
    {
        ft_swap_lst(stack_a);
        ft_swap_lst(stack_b);
        return (0);
    }
    if(!ft_strcmp(line, "pa\n"))
        return (ft_push_lst(stack_b, stack_a), 0);
    if(!ft_strcmp(line, "pb\n"))
        return (ft_push_lst(stack_a, stack_b), 0);
    if(!ft_strcmp(line, "ra\n"))
        return (ft_rotate_lst(stack_a), 0);
    if(!ft_strcmp(line, "rb\n"))
        return (ft_rotate_lst(stack_b), 0);
    if(!ft_strcmp(line, "rr\n"))
    {
        ft_rotate_lst(stack_a);
        ft_rotate_lst(stack_b);
        return (0);
    }
    if(!ft_strcmp(line, "rra\n"))
        return (ft_reverse_rotate_lst(stack_a), 0);
    if(!ft_strcmp(line, "rrb\n"))
        return (ft_reverse_rotate_lst(stack_b), 0);
    if(!ft_strcmp(line, "rrr\n"))
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
    int j;

    a = NULL;
    b = NULL;
    i = 0;
    while (av[i])
    {
        if (av[i][0] == '\0')
            return (ft_putendl_fd("Error", 2), 0);
        i++;
    }
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (0);
    i = 0;
    while (++i < ac)
    {
        split_args = ft_split(av[i], ' ');
        if(!split_args)
            return (ft_putendl_fd("Error", 2), 0);
        if(!ft_check_arguments(ft_count_split(split_args), split_args))
        {
            ft_free_split(split_args);
            return (ft_putendl_fd("Error", 2), 0);
        }
        j = i + 1;
		while (av[j] != NULL)
		{
            if (av[i][0] == '\0')
            {
                if (split_args)
                    ft_free_split(split_args);
                return (ft_putendl_fd("Error", 2), 0);
            }
			if (ft_strcmp(av[i], av[j]) == 0)
            {
                if (split_args)
                    ft_free_split(split_args);
				return (ft_putendl_fd("Error", 2), 0);
            }
			j++;
		}
        init_stack_a(&a, split_args);
        ft_free_split(split_args);
    }
    line = get_next_line(0);
    while (line != NULL)
    {
        if (read_operations(line, &a, &b))
        {
            if (line)
                free(line);
            ft_putendl_fd("Error", 2);
            return(-1);
        }
        free(line);
        line = get_next_line(0);
    }
    print_message(&a, &b);
    return (0);
}
