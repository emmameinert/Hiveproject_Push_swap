/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:33:53 by emeinert          #+#    #+#             */
/*   Updated: 2023/05/12 15:40:34 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_put_to_b(t_datab *data_b, t_data *data)
{
	int	i;
	int	*temp;

	temp = ft_make_temp(data, data_b, data_b->length);
	if (data_b->stack_b[0] == 0)
	{
		free(data_b->stack_b);
		ft_make_b_array(data, data_b);
		temp[0] = data->stack_a[0];
		data_b->stack_b[0] = temp[0];
	}
	else
	{
		i = -1;
		while (++i < data_b->length - 1)
			temp[i + 1] = data_b->stack_b[i];
		free(data_b->stack_b);
		ft_make_b_array(data, data_b);
		temp[0] = data->stack_a[0];
		i = -1;
		while (++i < data_b->length)
			data_b->stack_b[i] = temp[i];
	}
	free(temp);
}

void	ft_subtract(t_data *data, t_datab *data_b)
{
	int	*temp;
	int	i;

	i = 0;
	if (data->length == 0)
		return ;
	temp = malloc(sizeof(int *) * (data->length));
	if (!temp)
	{
		free(data);
		exit(1);
	}
	temp = ft_fill(temp, data->stack_a, data->length);
	free(data->stack_a);
	ft_make_array(data, data_b);
	while (i < data->length)
	{
		data->stack_a[i] = temp[i];
		i++;
	}
	free(temp);
}

void	ft_pb(t_data *data, t_datab *data_b)
{
	if (!data->length)
		return ;
	data_b->length++;
	ft_put_to_b(data_b, data);
	data->length--;
	ft_subtract(data, data_b);
	ft_printf("pb\n");
}
