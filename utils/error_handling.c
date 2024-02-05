#include "push_swap.h"

void    free_stack(t_list **stack)
{
    t_list *tmp;
    t_list *curr_node;

    if (!*stack)
        return ;
    curr_node = *stack;
    while (curr_node)
    {
        tmp = curr_node->next;
        free(curr_node);
        curr_node = tmp;
    }
    *stack = NULL;
}