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

#include "../push_swap.h"

bool check_num(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = 0;
        if (av[i][0] == '-' || av[i][0] == '+')
        {
            while (ft_isdigit(av[i][j + 1]) && av[i][j + 1])
                j++;
            if (av[i][j + 1])
                return (false);
        }
        else
        {
            while (av[i][j])
            {
                if (ft_isdigit(av[i][j]))
                    j++;
                else
                    return (false);
            }
        }
        i++;
    }
    return (true);
}

bool check_int(char **av)
{
    int i;
    long num;

    i = 1;
    while (av[i])
    {
        num = ft_atol(av[i]);
        if (num < INT_MIN || num > INT_MAX)
            return (false);    
        i++;
    }
    return (true);
}

bool check_double(char **av)
{
    int i;
    int j;

    j = 0;
    i = 1;
    while (av[i])
    {
        j = i + 1;
        while (av[j])
        {
            if (ft_atol(av[i]) == ft_atol(av[j]))
                return (false);
            j++;
        }
        i++;
    }
    return (true);
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

void    init_stack(t_stack **a, char **av)
{
    int i;

    i = 0;
    if (check_num(av) && check_int(av) && check_double(av))
    {
        while (av[i])
        {
            add_node_end(a, (int)ft_atol(av[i]));
            i++;
        }
    }
    else
    {
        free_stack(a);
        write(1, "Error\n", 6);
        exit(1);
    }
}
