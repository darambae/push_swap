/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:14:40 by dabae             #+#    #+#             */
/*   Updated: 2023/12/28 09:14:42 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_num(char **argv)
{
    int i;

    i = 1;
    while (argv[i][j])
    {
        j = 0;
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
                return 0;
            j++;
        }
        i++;
    }
    return (1);
}

static int check_int(char **av)
{
    int i;
    long num;

    i = 1;
    while (av[i])
    {
        num = ft_atol(av[i]);
        if (num < -2147483648 || num > 2147483647)
            return (0);    
        i++;
    }
    return (1);
}

static int check_double(char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        j = i + 1;
        while (av[j])
        {
            if (ft_atol(av[i]) == ft_atol(av[j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

long    ft_atol(const char *nptr)
{
	int	sign;
	long	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\v' || nptr[i] == '\f'
			|| nptr[i] == '\r' || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

void    init_stack(t_list **a, char **av)
{
    t_list *new;
    int i;

    i = 1;
    if (check_num(av) && check_int(av) && check_double(av))
    {
        while (av[i])
        {
            new = NULL;
            new = ft_lstnew(ft_atol(av[i]));
            ft_lstadd_back(a, new);
            i++;
        }
    }
}
