#include "push_swap.h"

t_list  *find_target(t_list **stack_a, t_list **stack_b)
{
    t_list *target;
    int smallest;

    while (stack_a)
    {
        smallest = stack_a->num - stack_b->num;
        while (stack_b)
        {
            if (smallest < 0)
                target = ft_max(*stack_b);
        }
        stack_a = stack_a->next;
    }
    target = NULL;
}