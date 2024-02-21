/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:30:01 by dabae             #+#    #+#             */
/*   Updated: 2024/02/21 16:26:18 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    find_target_in_b(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *target;
    t_stack *curr_b;
    long closest_smaller;

    target = NULL;
    curr_b = NULL;
    while (stack_a)
    {
        closest_smaller = LONG_MIN;
        curr_b = stack_b;
        while (curr_b)
        {
            if (curr_b->num < stack_a->num && curr_b->num > closest_smaller)
            {
                closest_smaller = curr_b->num;
                target = curr_b;
            }
            curr_b = curr_b->next;
        }
        if (closest_smaller == LONG_MIN)
            stack_a->target = ft_max_node(stack_b);
        else
            stack_a->target = target;
        stack_a = stack_a->next;
    }
}

void  calcul_cost_a(t_stack *a, t_stack *b)
{
    int size_a;
    int size_b;

    size_a = stack_size(a);
    size_b = stack_size(b);

    while (a)
    {
        a->cost = 0;
        if (a->before_median && a->target->before_median)
            a->cost = is_bigger(a->index, a->target->index);
        else if (!(a->before_median) && !(a->target->before_median))
            a->cost = is_bigger((size_a - a->index), (size_b - a->target->index));
        else if (a->before_median && !(a->target->before_median))
            a->cost = a->index + size_b - a->target->index;  
        else
            a->cost = size_a - a->index + a->target->index;
        a = a->next;
    }
}

void    set_cheapest(t_stack *stack_a)
{
    long min_cost;
    t_stack *cheapest_node;

    if (!stack_a)
        return ;
    min_cost = LONG_MAX;
    while (stack_a)
    {
        if (stack_a->cost < min_cost)
        {
            min_cost = stack_a->cost;
            cheapest_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    cheapest_node->cheapest = true;
}

static t_stack *get_cheapest_node(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL); 
}

void    push_cheapest_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *cheapest;

    cheapest = get_cheapest_node(*stack_a);
    if (cheapest->before_median && cheapest->target->before_median)
    {
        while (*stack_a != cheapest && *stack_b != cheapest->target)
            rr(stack_a, stack_b, 1);
        set_index_median(*stack_a);
        set_index_median(*stack_b);
    }
    else if (!(cheapest->before_median) && !(cheapest->target->before_median))
    {
        while (*stack_a != cheapest && *stack_b != cheapest->target)
            rrr(stack_a, stack_b, 1);
        set_index_median(*stack_a);
        set_index_median(*stack_b);
    }
    to_top(stack_a, cheapest, 'a');
    to_top(stack_b, cheapest->target, 'b');
    pb(stack_a, stack_b, 1);
}
