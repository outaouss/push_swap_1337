/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: outaouss <outaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:06:55 by outaouss          #+#    #+#             */
/*   Updated: 2026/01/03 15:41:30 by outaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

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

long	ft_atoi(char *str, t_node **stack, char **av)
{
	long	result;
	int		i;
	int		sign;

	(void)av;
	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			error_exit_av(stack, av);
		i++;
	}
	if (str[i] != '\0')
		error_exit_av(stack, av);
	return (result * sign);
}

int	has_duplicated(t_node *stack_a, long checker, char **av)
{
	t_node	*tmp;

	(void)av;
	if (!stack_a)
		return (0);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->value == checker)
			error_exit_av(&stack_a, av);
		tmp = tmp->next;
	}
	return (0);
}
