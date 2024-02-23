/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:54:09 by dabae             #+#    #+#             */
/*   Updated: 2024/02/23 14:12:11 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	find_index(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->num == num)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

void	min_to_top(t_stack **stack_a)
{
	while ((*stack_a)->num != ft_min_node(*stack_a)->num)
	{
		if (ft_min_node(*stack_a)->before_median)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	swap_3(t_stack **stack)
{
	t_stack	*max;
	int		index_max;

	set_index_median(*stack);
	max = ft_max_node(*stack);
	index_max = find_index(*stack, max->num);
	if (index_max == 0)
		ra(stack, 1);
	else if (index_max == 1)
		rra(stack, 1);
	if (!check_sorted(*stack))
		sa(stack, 1);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	size_lst;

	size_lst = stack_size(*a);
	if (size_lst == 2)
		sa(a, 1);
	else if (size_lst == 3)
		swap_3(a);
	else if (size_lst == 5)
		swap_5(a, b);
	else
		swap_big(a, b);
}
