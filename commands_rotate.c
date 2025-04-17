#include "push_swap.h"

void ra(Node **stack_a, Node **stack_b, bool print)
{
    rotate(stack_a);
    index_nodes(*stack_a, *stack_b);
    if (print == true)
        ft_printf("ra\n");
    return ;
}

void rb(Node **stack_a, Node **stack_b, bool print)
{

    rotate(stack_b);
    index_nodes(*stack_a, *stack_b);
    if (print == true)
        ft_printf("rb\n");
    return ;
}

void rr(Node **stack_a, Node **stack_b)
{
    ra(stack_a, stack_b, false);
    rb(stack_a, stack_b, false);
    ft_printf("rr\n");
    return ;
}
