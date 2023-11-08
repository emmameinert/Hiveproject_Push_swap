/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:42:12 by emeinert          #+#    #+#             */
/*   Updated: 2023/05/15 12:57:22 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort(int *a, int len)
{
	int	i;
	int	step;

	i = 0;
	step = i + 1;
	while (step < len)
	{
		if (a[i] > a[step])
			ft_swap(&a[i], &a[step]);
		i++;
		step++;
	}
	len--;
	if (len > 0)
		ft_sort(a, len);
}

void	ft_convert_for_radix(t_data *data, t_datab *data_b)
{
	int	i;
	int	j;

	i = -1;
	data->cpy = malloc(sizeof(int *) * (data->length));
	if (!data->cpy)
		ft_abort(data, data_b);
	while (++i < data->length)
		data->cpy[i] = data->stack_a[i];
	ft_sort(data->cpy, data->length);
	i = -1;
	while (++i < data->length)
	{
		j = -1;
		while (++j < data->length)
		{
			if (data->stack_a[i] == data->cpy[j])
			{
				data->stack_a[i] = j + 1;
				break ;
			}
		}
	}
	data->bits = ft_binary(data->cpy[data->length - 1]);
	free(data->cpy);
}

int	ft_binary(int n)
{
	int	i;
	int	temp;

	i = 0;
	while (n > 0)
	{
		temp = n % 2;
		n = n / 2;
		i++;
	}
	return (i);
}

void	ft_radix(t_data *data, t_datab *data_b)
{
	int	i;
	int	count;
	int	bits;

	bits = 0;
	while ((bits < data->bits) && (ft_check_if_sorted(data) != 2))
	{
		count = data->length;
		while (count > 0)
		{
			if ((data->stack_a[0] >> bits & 1) == 0)
				ft_pb(data, data_b);
			else if ((data->stack_a[0] >> bits & 1) == 1)
				ft_ra(data);
			count--;
		}
		while (data_b->length > 0)
			ft_pa(data, data_b);
		bits++;
	}
}

void	ft_sort_big_stack(t_data *data, t_datab *data_b)
{
	ft_convert_for_radix(data, data_b);
	ft_radix(data, data_b);
}
