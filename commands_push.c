#include "push_swap.h"

void pa(Node **stack_a, Node **stack_b)
{
    push(stack_b, stack_a);
    index_nodes(*stack_a, *stack_b);
    ft_printf("pa\n");
    return ;
}

void pb(Node **stack_a, Node **stack_b)
{
    push(stack_a, stack_b);
    index_nodes(*stack_a, *stack_b);
    ft_printf("pb\n");
    return ;
}
