#include "push_swap.h"

void rra(Node **stack_a, Node **stack_b, bool print)
{
    rotate_reverse(stack_a);
    index_nodes(*stack_a, *stack_b);
    if (print == true)
        ft_printf("rra\n");
    return ;
}

void rrb(Node **stack_a, Node **stack_b, bool print)
{
    rotate_reverse(stack_b);
    index_nodes(*stack_a, *stack_b);
    if (print == true)
        ft_printf("rrb\n");
    return ;
}

void rrr(Node **stack_a, Node **stack_b)
{
    rra(stack_a, stack_b, false);
    rrb(stack_a, stack_b, false);
    ft_printf("rrr\n");
    return ;
}

