#include "include/checker.h"

static int    execute_actions(t_stack **a, t_stack **b, char *str)
{
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
    else
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

static int	read_actions(t_stack *a, t_stack *b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(1);
		if (str == NULL)
            break ;
		if (execute_actions(&a, &b, str) == EXIT_FAILURE)
        {
            write(2, "Error\n", 6);
            free(str);
            return (EXIT_FAILURE);
        }
        free(str);
    }
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac == 1)
        return (EXIT_SUCCESS);
    else if (ac == 2)
	{
		av = split_argv(av[1], ' ');
		init_stack(&a, av);
	}
	else
		init_stack(&a, av + 1);
    b = NULL;
    if (read_actions(a, b) == EXIT_SUCCESS)
    {
        if (check_sorted(a) && !stack_size(b))
        {
            write(1, "OK\n", 3);
            free_stack(&a);
            return (EXIT_SUCCESS);
        }
        else
            write(1, "KO\n", 3);
	}
    if (ac == 2)
		ft_free_tab(av);
    free_stack(&a);
    free_stack(&b);
    return (EXIT_FAILURE);
}