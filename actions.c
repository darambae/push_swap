/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:52:31 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 12:53:34 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void	sa(t_list **a)
{
    t_list  *tmp;
    
    if (!a || !(a->next))
        return a;
    tmp =  (*a)->next;
    (*a)->next = tmp->next;
    tmp->next = (*a);
    (*a) = tmp;
    ft_printf("sa\n");
}

void	sb(t_list **b)
{
    t_list  *tmp;
    
    if (!b || !(b->next))
        return b;
    tmp =  (*b)->next;
    (*b)->next = tmp->next;
    tmp->next = (*b);
    (*b) = tmp;
    ft_printf("sb\n");

}

void	ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
    ft_printf("ss\n");

}

void	push(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (!*b)
        return ;
    tmp = (*b)->next;
    ft_lstadd_front(a, *b);
    *b = tmp;
}

void    pa(t_list **a, t_list **b)
{
    push(a, b);
    ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
    push(b, a);
    ft_printf("pb\n");
}

void	rotate(t_list **a)
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
    ra(a);
    rb(b);
    ft_printf("rr\n");
}

void	rra(t_list **a)
{
    t_list  *last;

    last = ft_listlast(a);
    last->prev = NULL;
    last->next = (*a);
    (*a)->prev = last;
    ft_printf("rra\n");
}
void	rrb(t_list **b)
{
    t_list  *last;

    last = ft_listlast(b);
    last->prev = NULL;
    last->next = (*b);
    (*b)->prev = last;
    ft_printf("rrb\n");
}
void	rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
    ft_printf("rrr\n");
}
