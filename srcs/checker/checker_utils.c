
#include "checker.h"

void	read_actions(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(1);
		if (str == NULL)
            break;
        else
			execute_actions(a, b, str);
	}
}

void    execute_actions(t_stack **a, t_stack **b, char *str)
{
    if (!str)
        return;
    if (!ft_strcmp(str, "pa\n"))
        pa(a, b, 0);
    else if (!ft_strcmp(str, "pb\n"))
        pb(a, b, 0);
    else if (!ft_strcmp(str, "ra\n"))
        ra(a, 0);
    else if (!ft_strcmp(str, "rb\n"))
        rb(b, 0);
    else if (!ft_strcmp(str, "rr\n"))
        rr(a, b, 0);
    else if (!ft_strcmp(str, "rra\n"))
        rra(a, 0);
    else if (!ft_strcmp(str, "rrb\n"))
        rrb(b, 0);
    else if (!ft_strcmp(str, "rrr\n"))
        rrr(a, b, 0);
    else if (!ft_strcmp(str, "sa\n"))
        sa(a, 0);
    else if (!ft_strcmp(str, "sb\n"))
        sb(b, 0);
    else if (!ft_strcmp(str, "ss\n"))
        ss(a, b, 0);
}
