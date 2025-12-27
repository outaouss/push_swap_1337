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

long ft_atoi(char *str, t_node **stack)
{
    long result;
    int i;
    int sign;

    result = 0;
    i = 0;
    sign = 1;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i++] == '-')
            sign = -sign;
    }
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
    t_node *tmp;
    
    if (!stack_a)
        return 0;
    tmp = stack_a;
    while (tmp)
    {
        if (tmp->value == checker)
            error_exit(&stack_a);
        tmp = tmp->next;
    }
    return (0);
}
