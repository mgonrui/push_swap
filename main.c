#include "push_swap.h"

static bool stack_in_order(Node *stack)
{
    while(stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return false;
        stack = stack->next;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        ft_printf("No args provided, please try again.");
        return 0;
    }
    Node *root_a;
    Node *root_b;
    int i;
    root_a = NULL;
    root_b = NULL;

    i = 1;
    if (ft_strchr(argv[i], ' '))
    {
        argv = input_is_in_quotes(&argc, argv);
        i = 0;
    }
    if (input_is_wrong(&argv[i]) || argv[1][0] == '\0')
    {
        ft_putstr_fd("Error", 2);
        return 0;
    }
    while(i < argc)
    {
        add_end_node(&root_a, ft_atoi(argv[i]));
        i++;
    }
    if (stack_in_order(root_a))
        return 0;
    sort_all(&root_a, &root_b);
    return 0;
}

