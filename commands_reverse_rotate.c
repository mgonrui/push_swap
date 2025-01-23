#include "push_swap.h"

void rra(Stacks roots)
{
    rotate_reverse(roots.a);
    return ;
}

void rrb(Stacks roots)
{
    rotate_reverse(roots.b);
    return ;
}

void rrl(Stacks roots)
{
    rra(roots);
    rrb(roots);
    return ;
}

