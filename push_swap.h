/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outaouss <outaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:06:35 by outaouss          #+#    #+#             */
/*   Updated: 2026/01/03 16:55:47 by outaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// |--> Used Libraries <--|

# include <unistd.h>
# include <stdlib.h>

// |--> Doubly Linked List Struct <--|

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

// |--> Mandatory Part <--|

void	ss(t_node **stack_a, t_node **stack_b, int silent);
void	sb(t_node **stack_b, int silent);
void	sa(t_node **stack_a, int silent);
void	swap(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b, int silent);
void	rb(t_node **stack_b, int silent);
void	ra(t_node **stack_a, int silent);
void	rotate(t_node **stack);
void	reverse_rotate(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b, int silent);
void	rrb(t_node **stack_b, int silent);
void	rra(t_node **stack_a, int silent);
void	push(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b, int silent);
void	pb(t_node **stack_a, t_node **stack_b, int silent);
void	error_exit_av(t_node **stack, char **av);
void	free_stack(t_node **stack);
void	stack_add_back(t_node **stack, t_node *to_add);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack);
void	fill_stack_a(t_node **stack_a, char **av);
void	free_matrix(char **matrix);
void	assign_index(t_node *stack);
void	shank_sort_phase1(t_node **stack_a, t_node **stack_b);
void	shank_sort_phase2(t_node **stack_a, t_node **stack_b);
void	digit_checker(char c, char **av, t_node **stack);
void	sort_kingdom(t_node **stack_a, t_node **stack_b);
t_node	*find_last_node(t_node *lst);
t_node	*create_node(long value, t_node **stack, char **av);
t_node	*find_max_index(t_node *stack);
t_node	*find_min_index(t_node *stack);
size_t	ft_strlen(const char *str);
long	ft_atoi(char *str, t_node **stack, char **av);
int		put_inside(char **new_str, const char *s, int *i, char c);
int		has_duplicated(t_node *stack_a, long checker, char **av);
int		count_words(const char *s, char c);
int		is_sorted(t_node *stack);
int		stack_len(t_node *stack);
int		get_position(t_node *stack, t_node *target);
char	**ft_split(char const *s, char c);
char	**free_arr(char **arr, int index_c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

// |--> Bonus Part <--|

int		ft_strcmp(char *s1, char *s2);
int		executed_cmd(char *cmd, t_node **a, t_node **b);
char	*get_next_line(int fd);

#endif