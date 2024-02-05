/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:53:41 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 13:53:44 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    add_node(t_list **stack, int num)
{
    t_list *new;
    t_list *last;

    if (!stack)
        return;
    new = malloc(sizeof(t_list));
    if (!new)
        return;
    new->next = NULL;
    new->num = num;
    if (!(*stack))
    {
        *stack = new;
        new->prev = NULL;
    }
    else
    {
        last = ft_lstlast(*stack);
        last->next = new;
        new->prev = last;
    }
}
t_list  *ft_second_last_node(t_list *stack)
{
    while (stack && stack->next && !(stack->next->next))
        stack = stack->next;
    return (stack);
}

t_list  *ft_max_node(t_list *stack)
{
    int max;
    t_list *max_node;

     if (!stack)
        return (NULL);
    max = stack->num;
    while (stack)
    {
        if (stack->num > max)
        {
            max = stack->num;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}

t_list  *ft_min_node(t_list *stack)
{
    int min;
    t_list *min_node;

    if (!stack)
        return (NULL);
    min = stack->num;
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

t_list *get_cheapest_node(t_list *stack)
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
