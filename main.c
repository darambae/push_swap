/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:55:39 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 12:59:41 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;
	t_list	*new;
	t_list	**stack;

	i = 1;
	if (ac > 1)
	{
		stack = NULL;
		while (i < ac)
		{
			new = ft_lstnew(ft_atoi(av[i]));
			new->index = i - 1;
			ft_lstadd_last(stack, new);
			i++;
		}
		if (check_sorted(stack))
			return (ft_printf("OK"));
		else
			push_swap(stack);
	}
	return (0);
}
