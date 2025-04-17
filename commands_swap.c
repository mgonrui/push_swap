#include "push_swap.h"

void sa(Node **stack_a, Node **stack_b, bool print)
{
   swap(stack_a);
   index_nodes(*stack_a, *stack_b);
   if (print == true)
      ft_printf("sa\n");
   return ;
}

void sb(Node **stack_a, Node **stack_b, bool print)
{
   swap(stack_b);
   index_nodes(*stack_a, *stack_b);
   if (print == true)
      ft_printf("sb\n");
   return ;
}

void ss(Node **stack_a, Node **stack_b)
{
   sa(stack_a, stack_b, false);
   sb(stack_a, stack_b, false);
   ft_printf("ss\n");
   return ;
}
