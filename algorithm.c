/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:12:10 by dabae             #+#    #+#             */
/*   Updated: 2024/02/23 11:17:12 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	prep_to_pb(t_stack **stack_a, t_stack **stack_b)
{
	set_index_median(*stack_a);
	set_index_median(*stack_b);
	find_target_in_b(*stack_a, *stack_b);
	calcul_cost_a(*stack_a, *stack_b);
	set_cheapest(*stack_a);
}

static void	prep_to_pa(t_stack **stack_a, t_stack **stack_b)
{
	set_index_median(*stack_a);
	set_index_median(*stack_b);
	find_target_in_a(*stack_a, *stack_b);
}

void	swap_5(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	while (size_a-- > 3 &&!check_sorted(*a))
	{
		set_index_median(*a);
		min_to_top(a);
		pb(a, b, 1);
	}
	swap_3(a);
	while (stack_size(*b))
		pa(a, b, 1);
}

void	swap_big(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size-- > 3 && !check_sorted(*stack_a))
		pb(stack_a, stack_b, 1);
	if (size-- > 3 && !check_sorted(*stack_a))
		pb(stack_a, stack_b, 1);
	while (size-- > 3 && !check_sorted(*stack_a))
	{
		prep_to_pb(stack_a, stack_b);
		push_cheapest_a_to_b(stack_a, stack_b);
	}
	swap_3(stack_a);
	while (stack_size(*stack_b))
	{
		prep_to_pa(stack_a, stack_b);
		push_back_b_to_a(stack_a, stack_b);
	}
	set_index_median(*stack_a);
	min_to_top(stack_a);
}
