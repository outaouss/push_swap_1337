# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
    struct s_node *previous;
} t_node;

void ss(t_node **stack_a, t_node **stack_b);
void sb(t_node **stack_b);
void sa(t_node **stack_a);
void swap(t_node **stack);
void print_stack(t_node *head);
void rr(t_node **stack_a, t_node **stack_b);
void rb(t_node **stack_b);
void ra(t_node **stack_a);
void rotate(t_node **stack);
t_node *find_last_node(t_node *lst);
void reverse_rotate(t_node **stack);
void rrr(t_node **stack_a, t_node **stack_b);
void rrb(t_node **stack_b);
void rra(t_node **stack_a);
void push(t_node **stack_a, t_node **stack_b);
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);
void error_exit(t_node **stack);
void free_stack(t_node **stack);
long ft_atoi(char *str, t_node **stack);
int has_duplicated(t_node *stack_a, long checker);
void stack_add_back(t_node **stack, t_node *to_add);
t_node *create_node(long value, t_node **stack);
void fill_stack_a(t_node **stack_a, char **av);
char	**ft_split(char const *s, char c);
int	put_inside(char **new_str, const char *s, int *i, char c);
char	**free_arr(char **arr, int index_c);
int	count_words(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void free_matrix(char **matrix);
void assign_index(t_node *stack);
int is_sorted(t_node *stack);
int stack_len(t_node *stack);
void sort_three(t_node **stack);
void sort_five(t_node **stack_a, t_node **stack_b);
t_node *find_max_index(t_node *stack);
t_node *find_min_index(t_node *stack);

//// To Remove 

// void print_index(t_node *head);

#endif