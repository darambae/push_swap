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
#include "push_swap.h"

static void    swap(t_list **a)
{
    t_list  *tmp;
    
    if (!a || !(*a) || !((*a)->next))
        return ;
    tmp =  (*a)->next;
    (*a)->next = tmp->next;
    tmp->next = (*a);
    (*a) = tmp;
}
void	sa(t_list **a)
{
    swap(a);
    ft_printf("sa\n");
}

void	sb(t_list **b)
{
    swap(b);
    ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");

}





