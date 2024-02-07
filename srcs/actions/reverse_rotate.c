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
#include "../push_swap.h"

static void    reverse_rotate(t_stack **a)
{
    t_stack *last;
    t_stack *tmp;
    t_stack *second_last;

    tmp = *a;
    last = get_last_node(*a);
    *a = last;
    last->next = tmp;
    second_last = ft_second_last_node(*a);
    second_last->next = NULL;
}
void	rra(t_stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}
void	rrb(t_stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}
void	rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}