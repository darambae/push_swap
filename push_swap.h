/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:05:16 by dabae             #+#    #+#             */
/*   Updated: 2023/12/07 13:09:25 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

typedef struct s_list
{
	int	num;
	int	index;
	struct	s_list	*prev;
	struct	s_list	*next;
}		t_list;

void	r(t_list *a)
void	rr(t_list *a, t_list *b)
void	rrab(t_list *a)
void	rrr(t_list *a, t_list *b)
void	s(t_list *a)
void	ss(t_list *a, t_list *b)
void	p(t_list *a, t_list *b)
