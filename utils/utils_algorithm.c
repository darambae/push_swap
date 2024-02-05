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

void    set_index_median(t_list *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = ft_lstsize(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->before_median = true;
        else
            stack->before_median = false;
        i++;
        stack = stack->next;
    }
}

bool check_sorted(t_list *stack)
{
    while (stack->num < stack->next->num && stack)
        stack = stack->next;
    if (!stack)
        return (true);
    else
        return (false);
}

void    to_top(t_list **stack, t_list *node, char which_stack)
{
    while (*stack != node)
    {    
        if (which_stack == 'a')
        {
            if (node->before_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (which_stack == 'b')
        {
            if (node->before_median)
                rb(stack);
            else
                rrb(stack); 
        }
    }
}
