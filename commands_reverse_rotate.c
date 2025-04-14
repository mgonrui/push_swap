#include "push_swap.h"

void rra(Node **stack_a, Node **stack_b)
{
    rotate_reverse(stack_a);
    ft_printf("rra\n");
    return ;
}

void rrb(Node **stack_a, Node **stack_b)
{
    rotate_reverse(stack_b);
    ft_printf("rra\n");
    return ;
}

void rrr(Node **stack_a, Node **stack_b)
{
    rra(stack_a, stack_b);
    rrb(stack_a, stack_b);
    ft_printf("rrr\n");
    return ;
}

