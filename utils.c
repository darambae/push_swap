/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:53:41 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 13:53:44 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    ft_lstadd_back(t_list **stack, t_list *new)
{
    t_list  *last;

    last = ft_lstlast(*stack);
    last->new = new;
}

t_list  ft_second_last_node(t_list *stack)
{
    while (stack && stack->next && !(stack->next->next))
        stack = stack->next;
    return (stack);
}

int     ft_max(t_list *stack)
{
    int max;

    max = stack->num;
    while (stack)
    {
        if (stack->num > max)
            max = stack->num;
        stack = stack->next;
    }
    return max;
}

int     ft_min(t_list *stack)
{
    int min;

    min = stack->num;
    while (stack)
    {
        if (stack->num < min)
            min = stack->num;
        stack = stack->next;
    }
    return min;
}

int find_index(t_list *stack, int num)
{
    while (stack)
    {
        if (stack->num == num)
            return (stack->index);
        stack = stack->next;
    }
    return -1;
}

int check_sorted(t_list *stack)
{
    while (stack->num < stack->next->num && stack)
        stack = stack->next;
    if (!stack)
        return (1);
    else
        return (0);
}