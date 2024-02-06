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

void    swap_big(t_list **stack_a, t_list **stack_b)
{
    int stack_size;

    stack_size = ft_lstsize(stack_a);
    if (stack_size-- > 3 && !check_sorted(*stack_a))
        pb(stack_a, stack_b);
    if (stack_size-- > 3 && !check_sorted(*stack_a))
        pb(stack_a, stack_b);
    while (stack_size-- > 3 && !check_sorted(*stack_a))
    {
        set_index_median(stack_a);
        set_index_median(stack_b);
        find_target_in_b(*stack_a, *stack_b);
        calcul_cost_a(*stack_a, *stack_b);
        push_cheapest_a_to_b(stack_a, stack_b);
    }
    swap_3(stack_a);
    while (*stack_b)
    {
        set_index_median(stack_a);
        set_index_median(stack_b);
        find_target_in_a(*stack_a, *stack_b);
        push_back_b_to_a(stack_a, stack_b);
    }
    set_index_median(*stack_a);
    to_top(stack_a, ft_min_node(*stack_a), 'a');
}