#include "push_swap.h"

static void free_double_ptr(void **ptr)
{
    int i = 0;
    while(ptr[i] != NULL)
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
}

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

void clean(Node *root_a, Node *root_b, char **argv, bool argv_modified)
{
    if (argv_modified == true)
        free_double_ptr((void **)argv);
    free_llist(root_a);
    free_llist(root_b);
}

void init_root(Node **root, int value)
{
    (*root) = malloc (sizeof(Node));
    (*root)->value = value;
    (*root)->prev = NULL;
    (*root)->index = 0;
    (*root)->next = NULL;
    return ;
}

int main(int argc, char **argv)
{
    Node *root_a;
    Node *root_b;
    int i;
    bool argv_modified = false;

    root_a = NULL;
    root_b = NULL;
    i = 1;
    if (ft_strchr(argv[i], ' '))
    {
        argv = input_is_in_quotes(&argc, argv);
        argv_modified = true;
        i = 0;
    }
    if (input_is_wrong(&argv[i]) || argv[1][0] == '\0')
    {
        ft_putstr_fd("Error", 2);
        return clean(root_a, root_b, argv, argv_modified), 0;
    }
    while(i < argc)
        add_end_node(&root_a, ft_atoi(argv[i++]));
    if (stack_in_order(root_a))
        return clean(root_a, root_b, argv, argv_modified), 0;
    sort_all(&root_a, &root_b);
    return clean(root_a, root_b, argv, argv_modified), 0;
}

