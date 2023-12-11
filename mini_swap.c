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
    {
        ra(stack);
    }
    else if (index_max == 1)
    {
        rra(stack);
    }
    if (!check_sorted(&stack))
        sa(stack);
}