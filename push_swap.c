/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:54:09 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 12:55:24 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	s(t_list *a)
{
    t_list  *tmp;
    
    if (!a || !(a->next))
        return a;
    tmp =  a->next;
    a->next = tmp->next;
    tmp->next = a;
    a = tmp;
}

void	ss(t_list *a, t_list *b)
{
    s(a);
    s(b);
}

void	p(t_list *a, t_list *b)
{
    if (!b)
        return ;
    b->next = a;
    a->prev = b;
}
