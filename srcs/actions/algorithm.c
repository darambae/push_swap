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
#include "../push_swap.h"

static int  find_index(t_stack *stack, int num)
{
    while (stack)
    {
        if (stack->num == num)
            return (stack->index);
        stack = stack->next;
    }
    return (-1);
}

void    swap_3(t_stack **stack)
{
    t_stack *max;
    int index_max;

    set_index_median(*stack);
    max = ft_max_node(*stack);
    index_max = find_index(*stack, max->num);
    if (index_max == 0)
        ra(stack);
    else if (index_max == 1)
        rra(stack);
    if (!check_sorted(*stack))
        sa(stack);
}

void    swap_big(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    size = stack_size(*stack_a);
    if (size-- > 3 && !check_sorted(*stack_a))
        pb(stack_a, stack_b);
    if (size-- > 3 && !check_sorted(*stack_a))
        pb(stack_a, stack_b);
    while (size-- > 3 && !check_sorted(*stack_a))
    {
        set_index_median(*stack_a);
        set_index_median(*stack_b);
        find_target_in_b(*stack_a, *stack_b);
        calcul_cost_a(*stack_a, *stack_b);
        push_cheapest_a_to_b(stack_a, stack_b);
    }
    swap_3(stack_a);
    while (*stack_b)
    {
        set_index_median(*stack_a);
        set_index_median(*stack_b);
        find_target_in_a(*stack_a, *stack_b);
        push_back_b_to_a(stack_a, stack_b);
    }
    set_index_median(*stack_a);
    to_top(stack_a, ft_min_node(*stack_a), 'a');
}