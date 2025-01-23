#include "push_swap.h"

void sa(Stacks roots)
{
   swap(roots.a);
   return ;
}

void sb(Stacks roots)
{
   swap(roots.b);
   return ;
}
void ss(Stacks roots)
{
   sa(roots);
   sb(roots);
   return ;
}
