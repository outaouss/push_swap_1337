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

/* --- Prototypes --- */
char    *ft_substr(char const *s, unsigned int start, size_t len);
long    ft_atoi(char *str, t_node **stack);
int     has_duplicated(t_node *stack_a, long checker);
void    fill_stack_a(t_node **stack_a, char **av);
void    assign_index(t_node *stack);
int     is_sorted(t_node *stack);
int     stack_len(t_node *stack);
void    sa(t_node **stack_a);
void    sort_three(t_node **stack);
void    sort_five(t_node **stack_a, t_node **stack_b);
void    k_sort_phase1(t_node **stack_a, t_node **stack_b);
void    k_sort_phase2(t_node **stack_a, t_node **stack_b);
int     get_position(t_node *stack, t_node *target);

/* --- Utility / Memory Management --- */

void free_stack(t_node **stack)
{
    t_node *tmp;
    if (!stack || !*stack)
        return ;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
    *stack = NULL;
}

void free_matrix(char **matrix)
{
    int i = 0;
    if (!matrix)
        return ;
    while (matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void error_exit(t_node **stack)
{
    if (stack && *stack)
        free_stack(stack);
    write(2, "Error\n", 6);
    exit(1);
}

size_t ft_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strdup(const char *s)
{
    size_t i = 0;
    size_t len_s = ft_strlen(s);
    char *dest = malloc(len_s + 1);
    if (!dest)
        return (NULL);
    while (s[i] != '\0')
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    char *substring;

    if (!s)
        return (NULL);
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    i = 0;
    substring = malloc(len + 1);
    if (!substring)
        return (NULL);
    while (i < len)
    {
        substring[i] = s[start + i];
        i++;
    }
    substring[i] = '\0';
    return (substring);
}

/* --- Split Logic --- */

int count_words(const char *s, char c)
{
    int count = 0, i = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i] && s[i] != c)
        {
            count++;
            while (s[i] && s[i] != c)
                i++;
        }
    }
    return (count);
}

char **free_arr(char **arr, int index_c)
{
    while (index_c > 0)
        free(arr[--index_c]);
    free(arr);
    return (NULL);
}

int put_inside(char **new_str, const char *s, int *i, char c)
{
    int start = *i;
    while (s[*i] && s[*i] != c)
        (*i)++;
    new_str[0] = ft_substr(s, start, *i - start);
    if (!new_str[0])
        return (0);
    return (1);
}

char **ft_split(char const *s, char c)
{
    char **new_string;
    int i = 0, word_index = 0;

    if (s == NULL)
        return (NULL);
    new_string = malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!new_string)
        return (NULL);
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
        {
            if (!put_inside(&new_string[word_index], s, &i, c))
                return (free_arr(new_string, word_index));
            word_index++;
        }
    }
    new_string[word_index] = NULL;
    return (new_string);
}

/* --- Node Operations --- */

t_node *create_node(long value, t_node **stack)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        error_exit(stack);
    new_node->value = value;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

void stack_add_back(t_node **stack, t_node *to_add)
{
    t_node *last;
    if (!stack || !to_add)
        return ;
    if (!*stack)
    {
        *stack = to_add;
        return ;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = to_add;
    to_add->previous = last;
}

t_node *find_last_node(t_node *lst)
{
    if (!lst)
        return NULL;
    while (lst->next)
        lst = lst->next;
    return lst;
}

t_node *find_max_index(t_node *stack)
{
    t_node *big_index;
    if (!stack)
        return NULL;
    big_index = stack;
    while (stack)
    {
        if (stack->index > big_index->index)
            big_index = stack;
        stack = stack->next;
    }
    return (big_index);
}

t_node *find_min_index(t_node *stack)
{
    t_node *min_index;
    if (!stack)
        return NULL;
    min_index = stack;
    while (stack)
    {
        if (stack->index < min_index->index)
            min_index = stack;
        stack = stack->next;
    }
    return (min_index);
}

/* --- Core Push Swap Operations --- */

void swap(t_node **stack)
{
    t_node *first, *seconde;
    if (!*stack || !(*stack)->next)
        return ;
    first = *stack;
    seconde = first->next;
    first->next = seconde->next;
    first->previous = seconde;
    if (seconde->next)
        seconde->next->previous = first;
    seconde->next = first; 
    seconde->previous = NULL;
    *stack = seconde;
}

void rotate(t_node **stack)
{
    t_node *first, *last;
    if (!*stack || !(*stack)->next)
        return ;
    first = *stack;
    last = find_last_node(*stack);
    *stack = first->next;
    (*stack)->previous = NULL;
    last->next = first;
    first->previous = last;
    first->next = NULL;
}

void reverse_rotate(t_node **stack)
{
    t_node *last;
    if (!*stack || !(*stack)->next)
        return ;
    last = find_last_node(*stack);
    if (last->previous)
        last->previous->next = NULL;
    last->next = *stack;
    last->previous = NULL;
    (*stack)->previous = last;
    *stack = last;
}

void push(t_node **src, t_node **dst)
{
    t_node *first_src;
    if (!*src)
        return ;
    first_src = *src;
    *src = first_src->next;
    if (*src)
        (*src)->previous = NULL;
    first_src->next = *dst;
    if (*dst)
        (*dst)->previous = first_src;
    *dst = first_src;
    (*dst)->previous = NULL;
}

/* --- Instructions --- */
void sa(t_node **stack_a) { swap(stack_a); write(1, "sa\n", 3); }
void sb(t_node **stack_b) { swap(stack_b); write(1, "sb\n", 3); }
void pa(t_node **stack_a, t_node **stack_b) { push(stack_b, stack_a); write(1, "pa\n", 3); }
void pb(t_node **stack_a, t_node **stack_b) { push(stack_a, stack_b); write(1, "pb\n", 3); }
void ra(t_node **stack_a) { rotate(stack_a); write(1, "ra\n", 3); }
void rb(t_node **stack_b) { rotate(stack_b); write(1, "rb\n", 3); }
void rra(t_node **stack_a) { reverse_rotate(stack_a); write(1, "rra\n", 4); }
void rrb(t_node **stack_b) { reverse_rotate(stack_b); write(1, "rrb\n", 4); }

/* --- Parser Logic --- */

long ft_atoi(char *str, t_node **stack)
{
    long result = 0;
    int i = 0, sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    if (!(str[i] >= '0' && str[i] <= '9'))
        error_exit(stack);
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i++] - '0');
        if (result * sign > 2147483647 || result * sign < -2147483648)
            error_exit(stack);
    }
    if (str[i] != '\0')
        error_exit(stack);
    return (result * sign);
}

int has_duplicated(t_node *stack_a, long checker)
{
    while (stack_a)
    {
        if (stack_a->value == checker)
            error_exit(&stack_a);
        stack_a = stack_a->next;
    }
    return (0);
}

void fill_stack_a(t_node **stack_a, char **av)
{
    int i = 0;
    long result;
    t_node *new_node;

    if (!av || !av[0])
        return ;
    while (av[i] != NULL)
    {
       result = ft_atoi(av[i], stack_a);
       has_duplicated(*stack_a, result);
       new_node = create_node(result, stack_a);
       stack_add_back(stack_a, new_node);
       i++;
    }
}

/* --- Algorithm Logic --- */

void assign_index(t_node *stack)
{
    int count;
    t_node *compare, *current = stack;
    while (current)
    {
        count = 0;
        compare = stack;
        while (compare)
        {
            if (compare->value < current->value)
                count++;
            compare = compare->next;
        }
        current->index = count;
        current = current->next;
    }
}

int is_sorted(t_node *stack)
{
    if (!stack || !stack->next)
        return 1;
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int stack_len(t_node *stack)
{
    int count = 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

int get_position(t_node *stack, t_node *target)
{
    int pos = 0;
    while (stack)
    {
        if (stack == target)
            return pos;
        pos++;
        stack = stack->next;
    }
    return pos;
}

void sort_three(t_node **stack)
{
    t_node *big_index = find_max_index(*stack);
    if (big_index == *stack)
        ra(stack);
    else if ((*stack)->next == big_index)
        rra(stack);
    if ((*stack)->index > (*stack)->next->index)
        sa(stack);
}

void sort_five(t_node **stack_a, t_node **stack_b)
{
    while(stack_len(*stack_a) > 3)
    {
        t_node *min_index = find_min_index(*stack_a);
        if (min_index == *stack_a)
            pb(stack_a, stack_b);
        else if (get_position(*stack_a, min_index) > stack_len(*stack_a) / 2)
            rra(stack_a);
        else
            ra(stack_a);
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
}

void k_sort_phase1(t_node **stack_a, t_node **stack_b)
{
    int i = 0, range;
    int len = stack_len(*stack_a);
    range = (len <= 100) ? 15 : 35;
    while (*stack_a)
    {
        if ((*stack_a)->index <= i)
        {
            pb(stack_a, stack_b);
            rb(stack_b);
            i++;
        }
        else if ((*stack_a)->index <= (i + range))
        {
            pb(stack_a, stack_b);
            i++;
        }
        else
            ra(stack_a);
    }
}

void k_sort_phase2(t_node **stack_a, t_node **stack_b)
{
    while (*stack_b)
    {
        t_node *max_node = find_max_index(*stack_b);
        int pos = get_position(*stack_b, max_node);
        int len = stack_len(*stack_b);
        while(*stack_b != max_node)
        {
            if (pos <= len / 2)
                rb(stack_b);
            else
                rrb(stack_b);
        }
        pa(stack_a, stack_b);
    }
}

/* --- Print Stack --- */

void print_stack(t_node *head)
{
    while (head)
    {
        printf("%d\n", head->value);
        head = head->next;
    }
}

/* --- Main --- */

int main(int ac, char **av)
{
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    char **args;
    int j = 1;

    if (ac < 2)
        return 0;
    while (av[j])
    {
        args = ft_split(av[j], ' ');
        fill_stack_a(&stack_a, args);
        free_matrix(args);
        j++;
    }
    assign_index(stack_a);
    if (!(is_sorted(stack_a)) && stack_len(stack_a) > 1)
    {
        int len = stack_len(stack_a);
        if (len == 2)
            sa(&stack_a);
        else if (len == 3)
            sort_three(&stack_a);
        else if (len <= 5)
            sort_five(&stack_a, &stack_b);
        else
        {
            k_sort_phase1(&stack_a, &stack_b);
            k_sort_phase2(&stack_a, &stack_b);
        }
    }
    print_stack(stack_a);
    free_stack(&stack_a);
    return (0);
}
