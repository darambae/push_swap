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
t_list	*create_list_a(int ac, char **av)
{
	int	i;
	t_list	*node;
	
	i = 1;
	
	while (i < ac)
	{
		node = malloc(sizeof(t_list));
		if (!node)
			return;
		node->index = i - 1;
		node->num = ft_atoi(av[i]);
		node->
		if ()
	}
	return (stack);
}
int	main(int ac, char **av)
{
	int	i;
	t_list	*new;
	t_list	*stack;
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			new = ft_lstnew(ft_atoi(av[i]));
	}
	

	return (0);
}
