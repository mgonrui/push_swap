#include "push_swap.h"

void print_targets(Node *root_b, Node *root_a)
{
    Node *current_b;
    Node *current_a;
    current_b = root_b;
    current_a = root_a;

    ft_printf("\nstack b target Nodes:\n ");
    while (current_b != NULL)
    {
        ft_printf("index: %d: value: %d target: %d top_half: %d cost: %d cheapest: %d\n ", current_b->index, current_b->value, current_b->target_node->value, current_b->on_top_half, current_b->cost, current_b->cheapest);
        current_b = current_b->next;
    }
    ft_printf("\nstack a target Nodes:\n ");
    while (current_a != NULL)
    {
        ft_printf("index: %d: value: %d top_half: %d\n",
                  current_a->index,
                  current_a->value,
                  current_a->on_top_half);
        current_a = current_a->next;
    }

    ft_printf("\n");
    return;
}

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
    sort_all(&root_a, &root_b);
    print_stack(root_a, root_b);
    return 0;
}

