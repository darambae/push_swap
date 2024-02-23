/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:55:39 by dabae             #+#    #+#             */
/*   Updated: 2024/02/22 17:34:47 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = split_argv(av[1], ' ');
		init_stack(&a, av);
	}
	else
		init_stack(&a, av + 1);
	if (!check_sorted(a))
		push_swap(&a, &b);
	free_stack(&a);
	if (ac == 2)
		ft_free_tab(av);
	return (0);
}
