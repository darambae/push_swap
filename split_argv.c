/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:14:20 by dabae             #+#    #+#             */
/*   Updated: 2024/02/23 13:55:11 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static	int	ft_count_arr(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s)
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	int	ft_size_wd(char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	check_argv_in_tab(char **arrs)
{
	if (!check_num(arrs) || !check_int(arrs) || !check_double(arrs))
	{
		ft_free_tab(arrs);
		write(2, "Error\n", 6);
		exit(1);
	}
}

char	**split_argv(char *s, char c)
{
	char	**arrs;
	int		i;
	int		z;
	int		size;

	arrs = (char **)malloc(sizeof(char *) * (ft_count_arr(s, c) + 1));
	if (!arrs)
		return (NULL);
	i = 0;
	z = -1;
	if (!ft_count_arr(s, c))
		exit(1);
	while (++z < ft_count_arr(s, c))
	{
		while (s[i] == c)
			i++;
		size = ft_size_wd(s, c, i);
		arrs[z] = ft_substr(s, i, size);
		if (!arrs[z])
			return (ft_free_tab(arrs));
		i += size;
	}
	arrs[z] = 0;
	check_argv_in_tab(arrs);
	return (arrs);
}
