/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:52:31 by dabae             #+#    #+#             */
/*   Updated: 2024/02/21 16:22:27 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **a)
{
    t_stack  *last;

    if (!*a || !(*a)->next)
        return ;
    last = get_last_node(*a);
    last->next = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    last->next->prev = last;
    last->next->next = NULL;

}    
void    ra(t_stack **a, bool print)
{
    rotate(a);
    if (print)
        write(1, "ra\n", 3);
}
void	rb(t_stack **b, bool print)
{
    rotate(b);
    if (print)
        write(1, "rb\n", 3);
}
void	rr(t_stack **a, t_stack **b, bool print)
{
    rotate(a);
    rotate(b);
    if (print)
        write(1, "rr\n", 3);
}
