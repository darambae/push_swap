
#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# include "get_next_line/get_next_line.h"

void    read_actions(t_stack **a, t_stack **b);
void    execute_actions(t_stack **a, t_stack **b, char *str);

#endif