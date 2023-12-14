#include "push_swap.h"

static void push(t_list **a, t_list **b)
{
    t_list  *tmp;

    if (!*b)
        return ;
    tmp = (*b)->next;
    ft_lstadd_front(a, *b);
    *b = tmp;
}

void    pa(t_list **a, t_list **b)
{
    push(a, b);
    ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
    push(b, a);
    ft_printf("pb\n");
}