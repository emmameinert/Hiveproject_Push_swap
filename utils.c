# include "pushswap.h"

t_data    *ft_make_data(void)
{
    t_data *data;
    data = malloc(sizeof(t_data));
    if (!data)
        exit(1);
    return (data);
}

t_datab *ft_make_datab(void)
{
	t_datab *data_b;
    data_b = malloc(sizeof(t_data));
    if (!data_b)
        exit(1);
    return (data_b);
}

void    ft_make_array(t_data *data)
{
	data->stack_a = malloc(sizeof(int *)* (data->length));
	if (!data->stack_a)
	{
		free(data);
		exit(1);
	}
}

int    *ft_fill(int *str, int *ptr, int length)
{
    int i;
    i = 0;
    while (i < length)
    {
        str[i] = ptr[i+1];
        i++;
    }
	return (str);
}

void	ft_make_b_array(t_datab *data_b)
{
	data_b->stack_b = malloc(sizeof(int *)* (data_b->length));
	if (!data_b->stack_b)
	{
		free(data_b);
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
void	ft_abort(t_data *data, t_datab *data_b)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data_b->stack_b)
		free(data_b->stack_b);
	if (data)
		free(data);
	ft_putendl_fd("Error", 2);
	exit(1);
}