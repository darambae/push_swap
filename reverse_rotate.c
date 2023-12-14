/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darambae <dabae@student.42perpignan.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:52:46 by dabae             #+#    #+#             */
/*   Updated: 2023/12/13 12:52:59 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

const void    reverse_rotate(t_list **a)
{
    t_list *last;
    t_list *tmp;
    t_list *second_last;

    tmp = *a;
    last = ft_lstlast(a);
    *a = last;
    last->next = tmp;
    second_last = ft_second_last_node(*a);
    second_last->next = NULL;
}
void	rra(t_list **a)
{
    reverse_rotate(a);
    ft_printf("rra\n");
}
void	rrb(t_list **b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}
void	rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr\n");
}
