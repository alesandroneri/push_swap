#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define TRUE 1
#define FALSE 0

#include "libft/libft.h"


typedef struct s_stack
{
	int					value;
	int					index;
	int					push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack; 

//stack functions
int ft_stack_size(t_stack *stack);
t_stack *ft_stack_last(t_stack *stack);
int ft_stack_sorted(t_stack *stack);
void init_stack_a(t_stack **a, char **av);
void fill_stack(t_stack **stack, int n);

//funcoes para pegar os maiores e menores valores
t_stack *find_min(t_stack *stack);
t_stack *find_max(t_stack *stack);

//sort algorithm
void sort_three(t_stack **stack);


//arguments
int ft_is_int(long nb, char **av, int i);
int ft_is_all_numbers(char *nb);
void    ft_check_arguments(int ac, char **av);

//operations
int ft_swap_lst(t_stack **stack);
int ft_sa(t_stack **stack_a);
int ft_sb(t_stack **stack_b);
int ft_ss(t_stack **stack_a, t_stack **stack_b);
int ft_push_lst(t_stack **stack_from, t_stack **stack_to);
int ft_pa(t_stack **stack_b, t_stack **stack_a);
int ft_pb(t_stack **stack_a, t_stack **stack_b);
int ft_rotate_lst(t_stack **stack);
int ft_ra(t_stack **stack_a);
int ft_rb(t_stack **stack_b);
int ft_rr(t_stack **stack_a, t_stack **stack_b);
int ft_reverse_rotate_lst(t_stack **stack);
int ft_rra(t_stack **stack_a);
int ft_rrb(t_stack **stack_b);
int ft_rrr(t_stack **stack_a, t_stack **stack_b);

#endif