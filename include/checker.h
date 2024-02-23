/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:48:46 by dabae             #+#    #+#             */
/*   Updated: 2024/02/23 13:49:10 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	bool			cheapest;
	bool			before_median;
	int				num;
	int				index;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
long	ft_atol(const char *nptr);
void	error_msg(t_stack **stack);
void	init_stack(t_stack **a, char **av);
char	**split_argv(char *s, char c);
char	**ft_free_tab(char **tab);
int		stack_size(t_stack *stack);
bool	check_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
#endif
