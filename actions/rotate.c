/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:52:31 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 12:53:34 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rotate(t_list **a)
{
    t_list  *last;
    t_list  *tmp;

    tmp = *a;
    *a = (*a)->next;
    last = ft_lstlast(a);
    tmp->next = NULL;
    last->next = tmp;
}
void    ra(t_list **a)
{
    rotate(a);
    ft_printf("ra\n");
}
void	rb(t_list **b)
{
    rotate(b)
    ft_printf("rb\n");
}
void	rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
