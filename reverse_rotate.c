/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:52:46 by dabae             #+#    #+#             */
/*   Updated: 2024/02/22 17:34:55 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void    reverse_rotate(t_stack **a)
{
    t_stack *last;

    if (!*a || !(*a)->next)
        return ;
    last = get_last_node(*a);
    last->prev->next = NULL;
    last->next = *a;
    last->prev = NULL;
    *a = last;
    last->next->prev = last;
}

void	rra(t_stack **a, bool print)
{
    reverse_rotate(a);
    if (print)
        write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool print)
{
    reverse_rotate(b);
    if (print)
        write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (print)
        write(1, "rrr\n", 4);
}
