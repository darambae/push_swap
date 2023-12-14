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

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

typedef struct s_list
{
	int	num;
	int	index;
	struct	s_list	*next;
}		t_list;

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
void    ft_lstadd_back(t_list **stack, t_list *new);
int     ft_max(t_list *stack);
int     ft_min(t_list *stack);
int 	find_index(t_list *stack, int num);
int 	check_sorted(t_list *stack);
t_list  ft_second_last_node(t_list *stack)

