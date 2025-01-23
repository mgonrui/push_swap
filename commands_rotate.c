#include "push_swap.h"

void ra(Stacks roots)
{
    rotate(roots.a);
    return ;
}

void rb(Stacks roots)
{

    rotate(roots.b);
    return ;
}

void rr(Stacks roots)
{
    ra(roots);
    rb(roots);
}
