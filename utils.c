# include "pushswap.h"

t_data    *ft_make_data(void)
{
    t_data *data;
    data = malloc(sizeof(t_data));
    if (!data)
        exit(1);
    return (data);
}

void    ft_make_array(t_data *data)
{
	data->stack_a = ft_calloc(sizeof(int *), (data->length));
	if (!data->stack_a)
	{
		free(data);
		exit(1);
	}
}


long	ft_atol(const char *str)
{
	long	i;
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if (sign * result > 2147483647)
			return (-1);
		if (sign * result < -2147483648)
			return (0);
	}
	return (sign * result);
}

void	freemystuffchar(char **str, int length)
{
	int		i;

	i = length;
	if (str == NULL || str[0] == NULL)
		return ;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}
void	ft_abort(t_data *data)
{
	if (data->stack_a)
		free(data->stack_a);
	// if (data->stack_b)
	// 	free(data->stack_b);
	if (data)
		free(data);
	ft_printf("ERROR\n");
	exit(1);
}