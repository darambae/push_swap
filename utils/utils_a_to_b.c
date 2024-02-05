#include "push_swap.h"

void  find_target_in_b(t_list *stack_a, t_list *stack_b)
{
    t_list *target;
    t_list *curr;
    long smallest;

    while (stack_a)
    {
        smallest = LONG_MIN;
        curr = stack_b;
        while (curr)
        {
            if (curr->num < stack_a->num && curr->num > smallest)
            {
                smallest = curr->num;
                target = curr;
            }
            curr = curr->next;
        }
        if (smallest == LONG_MIN)
            target = ft_max_node(stack_b);
        stack_a->target = target;
        stack_a = stack_a->next;
    }
}

void  calcul_cost_a(t_list *stack_a, t_list *stack_b)
{
    while (stack_a)
    {
        if (stack_a->before_median)
            stack_a->cost = stack_a->index;
        else
            stack_a->cost = ft_lstsize(stack_a) - stack_a->index;
        if (stack_a->target->before_median)
            stack_a->cost += stack_a->target->index;
        else
            stack_a->cost += ft_lstsize(stack_b) - stack_a->target->index;
        stack_a = stack_a->next;
    }
}

void    set_cheapest(t_list *stack_a)
{
    long min_cost;
    t_list *cheapest_node;

    if (!stack_a)
        return ;
    cheapest_node = LONG_MAX;
    while (stack_a)
    {
        if (stack_a->cost < min_cost)
        {
            min_cost = stack_a->cost;
            cheapest_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    cheapest_node->cheapest = true;
}
void    push_cheapest_a_to_b(t_list **stack_a, t_list **stack_b)
{
    t_list *cheapest;

    cheapest = get_cheapest_node(*stack_a);
    if (cheapest->before_median && cheapest->target->before_median)
    {
        while (*stack_a != cheapest && *stack_b != cheapest->target)
            rr(stack_a, stack_b);
        set_index_median(*stack_a);
        set_index_median(*stack_b);
    }
    else if (!(cheapest->before_median) && !(cheapest->target->before_median))
    {
        while (*stack_a != cheapest && *stack_b != cheapest->target)
            rrr(stack_a, stack_b);
        set_index_median(*stack_a);
        set_index_median(*stack_b);
    }
    to_top(stack_a, cheapest, 'a');
    to_top(stack_b, cheapest->target, 'b');
    pb(stack_b, stack_a);
}
