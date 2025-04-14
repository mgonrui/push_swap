#include "push_swap.h"

void sa(Node **root_a, Node **root_b)
{
   swap(root_a);
   ft_printf("sa\n");
   return ;
}

void sb(Node **root_a, Node **root_b)
{
   swap(root_b);
   ft_printf("sa\n");
   return ;
}

void ss(Node **root_a, Node **root_b)
{
   sa(root_a, root_b);
   sb(root_a, root_b);
   ft_printf("ss\n");
   return ;
}
