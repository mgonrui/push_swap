#include "push_swap.h"
#include <stdlib.h>

void print_stack(Node *root_a, Node *root_b)
{
    Node *current_a;
    Node *current_b;
    current_a = root_a;
    current_b = root_b;

    ft_printf("stack a: ");
    while (current_a != NULL)
    {
        ft_printf( " %d ", current_a->value);
        current_a = current_a->next;
    }
    ft_printf("\nstack b: ");
    while (current_b != NULL)
    {
        ft_printf(" %d ", current_b->value);
        current_b = current_b->next;
    }
    ft_printf("\n");

}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        ft_printf("No args provided, please try again.");
        return 0;
    }
    Stacks roots;
    Node *root_a;
    Node *root_b;
    int i;

    roots.a =  &root_a;
    roots.b =  &root_b;

    i = 1;
    if (ft_strchr(argv[i], ' '))
    {
        argv = input_is_in_quotes(&argc, argv);
        i = 0;
    }
    if (input_is_wrong(&argv[i]))
    {
        ft_printf("INPUT IS NOT VALID");
        return 0;
    }
    while(i < argc)
    {
        add_end_node(&root_a, ft_atoi(argv[i]));
        i++;
    }
    print_stack(root_a, root_b);
    /* sa(roots); */
    /* pb(roots); */
    /* pb(roots); */
    /* pb(roots); */
    /* ss(roots); */
    /* rr(roots); */
    /* rrl(roots); */


    ft_printf("\nstack after action: \n\n");
    print_stack(root_a, root_b);
    return 0;
}

