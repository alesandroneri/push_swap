/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:29:34 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/22 13:46:36 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				print_message(t_stack **stack_a, t_stack **stack_b);
int					read_operations(char *line, t_stack **stack_a,
						t_stack **stack_b);
int					ft_is_int(long nb);
int					ft_is_all_numbers(char *nb);
int					ft_count_split(char **split_args);
int					ft_check_arguments(int ac, char **av);
int					ft_push_lst(t_stack **stack_from, t_stack **stack_to);
int					ft_pa(t_stack **stack_b, t_stack **stack_a);
int					ft_pb(t_stack **stack_a, t_stack **stack_b);
int					ft_reverse_rotate_lst(t_stack **stack);
int					ft_rra(t_stack **stack_a);
int					ft_rrb(t_stack **stack_b);
int					ft_rrr(t_stack **stack_a, t_stack **stack_b);
int					ft_rotate_lst(t_stack **stack);
int					ft_ra(t_stack **stack_a);
int					ft_rb(t_stack **stack_b);
int					ft_rr(t_stack **stack_a, t_stack **stack_b);
int					ft_swap_lst(t_stack **stack);
int					ft_sa(t_stack **stack_a);
int					ft_sb(t_stack **stack_b);
int					ft_ss(t_stack **stack_a, t_stack **stack_b);
int					ft_stack_size(t_stack *stack);
t_stack				*ft_stack_last(t_stack *stack);
int					ft_stack_sorted(t_stack *stack);
void				init_stack_a(t_stack **a, char **av);
void				fill_stack(t_stack **stack, int n);
void				ft_print_stack(t_stack *stack);
int					ft_check_dup_stack(t_stack *stack);
void				ft_free_stack(t_stack **stack);
void				ft_free_split(char **strs);
void				ft_free_stacks(t_stack **stack_a, t_stack **stack_b);
int					valid_arguments(int ac, char **av, t_stack **stack_a);
int					read_operations(char *line, t_stack **stack_a,
						t_stack **stack_b);

#endif