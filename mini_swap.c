/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_swap.c                                        :+:      :+:    :+:   */
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

void    swap_5(t_list **stack_a, t_list **stack_b)
{
    int max_a;
    int min_a;
    
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    swap_3(stack_a);
    
    max_a = ft_max(*stack_a);
    min_a = ft_min(*stack_a);
    
    pa(stack_a, stack_b);

}