/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:15:25 by dabae             #+#    #+#             */
/*   Updated: 2023/12/28 09:15:28 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void push(t_stack **a, t_stack **b)
{
    t_stack  *tmp;

    if (!*b)
        return ;
    tmp = (*b)->next;
    add_node_front(a, *b);
    *b = tmp;
}

void    pa(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}
