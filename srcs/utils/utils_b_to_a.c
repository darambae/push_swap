/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:30:25 by dabae             #+#    #+#             */
/*   Updated: 2024/02/20 21:26:56 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    find_target_in_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *target;
    t_stack *curr_a;
    long closest_bigger;

    target = NULL;
    curr_a = NULL;
    closest_bigger = 0;
    while (stack_b)
    {
        closest_bigger = LONG_MAX;
        curr_a = stack_a;
        while (curr_a)
        {
            if (curr_a->num > stack_b->num && curr_a->num < closest_bigger)
            {
                closest_bigger = curr_a->num;
                target = curr_a;
            }
            curr_a = curr_a->next;
        }
        if (closest_bigger == LONG_MAX)
            stack_b->target = ft_min_node(stack_a);
        else
            stack_b->target = target;
        stack_b = stack_b->next;
    }
}
void    push_back_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    to_top(stack_a, (*stack_b)->target, 'a');
    pa(stack_a, stack_b);
}
