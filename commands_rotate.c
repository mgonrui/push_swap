#include "push_swap.h"

void ra(Node **stack_a, Node **stack_b)
{
    rotate(stack_a);
    ft_printf("ra\n");
    return ;
}

void rb(Node **stack_a, Node **stack_b)
{

    rotate(stack_b);
    ft_printf("rb\n");
    return ;
}

void rr(Node **stack_a, Node **stack_b)
{
    ra(stack_a, stack_b);
    rb(stack_a, stack_b);
    ft_printf("rr\n");
    return ;
}
