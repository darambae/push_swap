/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:14:50 by dabae             #+#    #+#             */
/*   Updated: 2023/12/28 09:14:53 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    set_index_median(t_list *stack)
{
    int len_stack;
    int median;

    len_stack = ft_lstsize(stack);
    median = len_stack / 2;
    return (median);
}

bool check_sorted(t_list *stack)
{
    while (stack->num < stack->next->num && stack)
        stack = stack->next;
    if (!stack)
        return (1);
    else
        return (0);
}

t_list  *find_target(t_list *stack_a, t_list *stack_b)
{
    t_list *target;
    t_list *curr;
    long smallest;

    while (stack_a)
    {
        smallest = LONG_MIN;
        curr = stack_b;
        while (curr)
        {
            if (curr->num < stack_a->num && curr->num > smallest)
            {
                smallest = curr->num;
                target = curr;
            }
            curr = curr->next;
        }
        if (smallest == LONG_MIN)
            target = ft_max_node(*stack_b);
        stack_a->target = target;
        stack_a = stack_a->next;
    }
    return (stack_a);
}

t_list  *calcul_cost(t_list *stack_a, t_list *stack_b)
{
    int cost_to_top_a;
    int cost_to_top_b;

    while (stack_a)
    {
        stack_a->target 
    }
    //
}