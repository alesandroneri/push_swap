#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"

//Stack
typedef struct s_list
{
    int value;
    int index;
    struct s_list *next;
    struct s_list *prev;
} t_list;


// Checagem dos argumentos recebidos
int ft_is_int(int nb, char **av, int i);
int ft_is_all_numbers(char *nb);
void    ft_check_arguments(int ac, char **av);


// Operações
int ft_swap_lst(t_list **stack);
int ft_sa(t_list **stack_a);
int ft_sb(t_list **stack_b);
int ft_ss(t_list **stack_a, t_list **stack_b);
int ft_push_lst(t_list **stack_from, t_list **stack_to);
int ft_pa(t_list **stack_b, t_list **stack_a);
int ft_pb(t_list **stack_a, t_list **stack_b);
int ft_rotate_lst(t_list **stack);
int ft_ra(t_list **stack_a);
int ft_rb(t_list **stack_b);
int ft_rr(t_list **stack_a, t_list **stack_b);
int ft_reverse_rotate_lst(t_list **stack);
int ft_rra(t_list **stack_a);
int ft_rrb(t_list **stack_b);
int ft_rrr(t_list **stack_a, t_list **stack_b);

#endif