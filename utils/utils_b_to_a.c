#include "push_swap.h"

t_list  *find_target_in_a(t_list *stack_a, t_list *stack_b)
{
    t_list *target;
    t_list *curr;
    long biggest;

    while (stack_b)
    {
        biggest = LONG_MAX;
        curr = stack_a;
        while (curr)
        {
            if (curr->num > stack_b->num && curr->num < biggest)
            {
                biggest = curr->num;
                target = curr;
            }
            curr = curr->next;
        }
        if (biggest == LONG_MAX)
            target = ft_max_node(stack_b);
        stack_b->target = target;
        stack_b = stack_b->next;
    }
    return (stack_a);
}
void    push_back_b_to_a(t_list **stack_a, t_list **stack_b)
{
    to_top(stack_a, (*stack_b)->target, 'a');
    pa(stack_a, stack_b);
}