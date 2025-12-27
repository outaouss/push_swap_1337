#include "../push_swap.h"

t_node *find_last_node(t_node *lst)
{
    if (!lst)
        return NULL;

    while ((lst)->next)
    {
        (lst) = (lst)->next;
    }
    return lst;
}

static void reverse_rotate(t_node **stack)
{
    t_node *last;

    if (!*stack || !(*stack)->next)
        return ;

    last = find_last_node(*stack);

    last->previous->next = NULL;

    last->next = *stack;
    last->previous = NULL;

    (*stack)->previous = last;
    *stack = last;
}

void rra(t_node **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void rrb(t_node **stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}

void rrr(t_node **stack_a, t_node **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}

void print_stack(t_node *head)
{
    while (head)
    {
        printf("%d\n", head->value);
        head = head->next;
    }
}


// int main()
// {
//     t_node *node1 = malloc(sizeof(t_node));
//     t_node *node2 = malloc(sizeof(t_node));
//     t_node *node3 = malloc(sizeof(t_node));

//     node1->value = 5;
//     node2->value = 6;
//     node3->value = 7;

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     node1->previous = NULL;
//     node2->previous = node1;
//     node3->previous = node2;

//     /////

//     t_node *node4 = malloc(sizeof(t_node));
//     t_node *node5 = malloc(sizeof(t_node));
//     t_node *node6 = malloc(sizeof(t_node));

//     node4->value = 8;
//     node5->value = 9;
//     node6->value = 7;

//     node4->next = node5;
//     node5->next = node6;
//     node6->next = NULL;

//     node4->previous = NULL;
//     node5->previous = node4;
//     node6->previous = node5;

//     printf("before rotate\n");
//     printf("stack a\n");
//     print_stack(node1);
//     printf("stack b\n");
//     print_stack(node4);
    
//     rrr(&node1, &node4);
    
//     printf("After Rotate\n");
//     printf("stack a\n");
//     print_stack(node1);
//     printf("stack b\n");
//     print_stack(node4);
// }