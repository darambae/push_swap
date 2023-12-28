/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:12:10 by dabae             #+#    #+#             */
/*   Updated: 2023/12/11 11:12:17 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    swap_3(t_list **stack)
{
    int max;
    int index_max;

    max = ft_max(stack);
    index_max = find_index(stack, max);
    if (index_max == 0)
        ra(stack);
    else if (index_max == 1)
        rra(stack);
    if (!check_sorted(&stack))
        sa(stack);
}

void    sort_descending(t_list **b)
{
    while (*b)
    {
        if ((*b)->num < (*b)->next->num)
            
        (*b) = (*b)->next;
    }
}
void    swap_big(t_list **stack_a, t_list **stack_b)
{
    t_list *max;
    t_list *min;

    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    while (ft_lstsize(stack_a) > 3)
    {
        sort_descending(stack_b);
        max = ft_min_node(*stack_b);
        min = ft_max_node(*stack_b);
        find_target(stack_a, stack_b);
    }
}