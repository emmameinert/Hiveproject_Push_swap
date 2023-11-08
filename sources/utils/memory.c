/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:22:08 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 13:59:09 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswap.h"

t_data	*ft_make_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putendl_fd("Error\n", 2);
		exit(1);
	}
	return (data);
}

t_datab	*ft_make_datab(t_data *data)
{
	t_datab	*data_b;

	data_b = malloc(sizeof(t_data));
	if (!data_b)
	{
		free(data);
		ft_putendl_fd("Error\n", 2);
		exit(1);
	}
	return (data_b);
}

void	ft_make_array(t_data *data, t_datab *data_b)
{
	data->stack_a = malloc(sizeof(int *) * (data->length));
	if (!data->stack_a)
		ft_abort(data, data_b);
}

void	ft_make_b_array(t_data *data, t_datab *data_b)
{
	data_b->stack_b = malloc(sizeof(int *) * (data_b->length));
	if (!data_b->stack_b)
		ft_abort(data, data_b);
}
