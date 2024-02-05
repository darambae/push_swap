/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:05:16 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 13:09:25 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
#define PUSH_SWAP_H

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_list
{
	int	num;
	int index;
	int cost;
	bool cheapest;
	bool before_median;
	
	struct s_list *target;
	struct s_list *next;
	struct	s_list	*prev;
} t_list;

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void swap_3(t_list **stack);
void swap_big(t_list **stack_a, t_list **stack_b);
void push_swap(t_list **stack_a, t_list **stack_b);
void to_top(t_list **stack, t_list *node, char which_stack);
void push_cheapest_a_to_b(t_list **stack_a, t_list **stack_b);
void    push_back_b_to_a(t_list **stack_a, t_list **stack_b);
char **split_argv(char *s, char c);
void add_node(t_list **stack, int nbr);
t_list 		*ft_max_node(t_list *stack);
t_list		*ft_min_node(t_list *stack);
t_list 		*get_cheapest_node(t_list *stack);
void set_index_median(t_list *stack);
bool check_sorted(t_list *stack);
t_list *ft_second_last_node(t_list *stack);
t_list *find_target_in_a(t_list *stack_a, t_list *stack_b);
void find_target_in_b(t_list *stack_a, t_list *stack_b);
void calcul_cost_a(t_list *stack_a, t_list *stack_b);
void set_cheapest(t_list *stack_a);
void free_stack(t_list **stack);

long ft_atol(const char *nptr);

#endif