/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:54:09 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 12:55:24 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void    push_swap(t_list **stack)
{
    int size_lst;

    size_lst = ft_lstsize(stack);
    if (size_lst <= 3)
    {
        swap_3(stack);
    }
    else if (size_lst <= 5)
    {

    }
    else if (size_lst <= 100)
    {

    }
    else
    {

    }
}
