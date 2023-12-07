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

void	r(t_list *a)
{
    t_list  *last;

    last = ft_lstlast(a);
    a->prev = last;
    a->next = NULL;
    last->next = a;
}

void	rr(t_list *a, t_list *b)
{
    r(a);
    r(b);
}

void	rrab(t_list *a)
{
    t_list  *last;

    last = ft_listlast(a);
    last->prev = NULL;
    last->next = a;
    a->prev = last;
}

void	rrr(t_list *a, t_list *b)
{
    rr(a);
    rr(b);
}
