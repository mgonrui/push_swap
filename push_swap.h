#ifndef PUSH_SWAP_H_
#define PUSH_SWAP_H_

# define MAX_INT 2147483647
# define MIN_INT -2147483648

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct Node
{
    int value;
    int index;
    int cost;
    bool on_top_half;
    bool cheapest;
    struct Node *target_node;
    struct Node *next;
    struct Node *prev;
} Node;

// basic llist actions
void remove_beggining_node(Node **root);
void add_beginning_node(Node **root, int value);
void add_end_node(Node **root, int value);
int count_nodes(Node *root);
void index_nodes(Node *root_a, Node *root_b);

// basic push swap actions
void swap(Node **root);
void push(Node **root_src, Node **root_dst);
void rotate(Node **root);
void rotate_reverse(Node **root);


// commands swap
void sa(Node **stack_a, Node **stack_b, bool print);
void sb(Node **stack_a, Node **stack_b, bool print);
void ss(Node **stack_a, Node **stack_b);
// commands push
void pa(Node **stack_a, Node **stack_b);
void pb(Node **stack_a, Node **stack_b);
// commands rotate
void ra(Node **stack_a, Node **stack_b, bool print);
void rb(Node **stack_a, Node **stack_b, bool print);
void rr(Node **stack_a, Node **stack_b);
//commands reverse rotate
void rra(Node **stack_a, Node **stack_b, bool print);
void rrb(Node **stack_a, Node **stack_b, bool print);
void rrr(Node **stack_a, Node **stack_b);
//user input
char **input_is_in_quotes(int *argc, char **argv);
bool input_is_wrong(char **argv);
// move_nodes
void sort_three(Node **stack_a, Node **stack_b);
void sort_all(Node **stack_a, Node **stack_b);
void move_nodes(Node **stack_a, Node **stack_b);
//algorythm
void find_target_node(Node *stack_a, Node *stack_b);
void calculate_cost(Node *stack_a, Node *stack_b);
void restart_stacks(Node *stack_a, Node *stack_b);
// stack utils
bool on_same_half_stack(Node *tomove);
Node *find_largest(Node *list);
Node *find_smallest(Node *list);
Node *flag_cheapest(Node *stack_b);


#endif // PUSH_SWAP_H_
