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

    if (!*stack)
    {
        *stack = new;
        new->prev = NULL;
    }
    else
    {
        last = ft_lstlast(*stack);
        new->prev = last;
        last->next = new;
    }
}

t_list  ft_second_last_node(t_list *stack)
{
    while (stack && stack->next && !(stack->next->next))
        stack = stack->next;
    return (stack);
}

t_list     *ft_max_node(t_list *stack)
{
    int max;
    t_list *max_node;

    max = stack->num;
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->num > max)
        {
            max = stack->num;
            max_node = stack;
        }
        stack = stack->next;
    }
    return max;
}

t_list     *ft_min_node(t_list *stack)
{
    int min;
    t_list *min_node;

    min = stack->num;
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->num < min)
        {
            min = stack->num;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

int find_node(t_list *stack, int num)
{
    while (stack)
    {
        if (stack->num == num)
            return (stack);
        stack = stack->next;
    }
    return (-1);
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



