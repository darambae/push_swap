/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:52:31 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 12:53:34 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static void    swap(t_stack **a)
{
    t_stack  *tmp;
    
    if (!a || !(*a) || !((*a)->next))
        return ;
    tmp =  (*a)->next;
    (*a)->next = tmp->next;
    tmp->next = (*a);
    (*a) = tmp;
}
void	sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}





