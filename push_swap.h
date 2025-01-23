#ifndef PUSH_SWAP_H_
#define PUSH_SWAP_H_

# define MAX_INT 2147483647
# define MIN_INT -2147483648

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"
// TODO delete header after finishing project
#include <stdio.h>

typedef struct Node
{
    int value;
    int index;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Stacks
{
    struct Node **a;
    struct Node **b;
} Stacks;

// basic llist actions
void remove_beggining_node(Node **root);
void add_beginning_node(Node **root, int value);
void add_end_node(Node **root, int value);

// basic push swap actions
void swap(Node **root);
void push(Node **root_src, Node **root_dst);
void rotate(Node **root);
void rotate_reverse(Node **root);


// commands swap
void sa(Stacks roots);
void sb(Stacks roots);
void ss(Stacks roots);
// commands push
void pa(Stacks roots);
void pb(Stacks roots);
// commands rotate
void ra(Stacks roots);
void rb(Stacks roots);
void rr(Stacks roots);
//commands reverse rotate
void rra(Stacks roots);
void rrb(Stacks roots);
void rrl(Stacks roots);

//user input
char **input_is_in_quotes(int *argc, char **argv);
int input_is_wrong(char **argv);

#endif // PUSH_SWAP_H_
