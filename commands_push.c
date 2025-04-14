#include "push_swap.h"

void pa(Node **root_a, Node **root_b)
{
    push(root_b, root_a);
    ft_printf("pa\n");
    return ;
}

void pb(Node **root_a, Node **root_b)
{
    push(root_a, root_b);
    ft_printf("pb\n");
    return ;
}
