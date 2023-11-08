/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:24:37 by emeinert          #+#    #+#             */
/*   Updated: 2023/05/12 15:33:46 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_subtract_b(t_data *data, t_datab *data_b)
{
	int	*temp;
	int	i;

	i = 0;
	if (data_b->length == 0)
		return ;
	temp = malloc(sizeof(int *) * (data_b->length));
	if (!temp)
	{
		free(data_b);
		exit(1);
	}
	temp = ft_fill(temp, data_b->stack_b, data_b->length);
	free(data_b->stack_b);
	ft_make_b_array(data, data_b);
	while (i < data_b->length)
	{
		data_b->stack_b[i] = temp[i];
		i++;
	}
	free(temp);
}

void	ft_pa(t_data *data, t_datab *data_b)
{
	if (!data_b->length)
		return ;
	data->length++;
	ft_put_to_a(data_b, data);
	data_b->length--;
	ft_subtract_b(data, data_b);
	ft_printf("pa\n");
}

void	ft_put_to_a(t_datab *data_b, t_data *data)
{
	int	i;
	int	*temp;

	temp = ft_make_temp(data, data_b, data->length);
	if (data->stack_a[0] == 0)
	{
		free(data->stack_a);
		ft_make_array(data, data_b);
		temp[0] = data_b->stack_b[0];
		data->stack_a[0] = temp[0];
	}
	else
	{
		i = -1;
		while (++i < data->length - 1)
			temp[i + 1] = data->stack_a[i];
		free(data->stack_a);
		ft_make_array(data, data_b);
		temp[0] = data_b->stack_b[0];
		i = -1;
		while (++i < data->length)
			data->stack_a[i] = temp[i];
	}
	free(temp);
}

int	*ft_make_temp(t_data *data, t_datab *data_b, int len)
{
	int	*temp;

	temp = malloc(sizeof(int *) * (len));
	if (!temp)
		ft_abort(data, data_b);
	return (temp);
}
