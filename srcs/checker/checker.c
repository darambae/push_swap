#include "checker.h"

int checker(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
	else if (ac == 2)
	{
		av = split_argv(av[1], ' ');
		init_stack(&a, av);
	}
	else
		init_stack(&a, av + 1);
    ft_free_tab(av);
    read_actions(&a, &b);
    if (check_sorted(a) && !stack_size(b))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    return (0);
}