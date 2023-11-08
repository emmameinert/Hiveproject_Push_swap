/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:48:43 by emeinert          #+#    #+#             */
/*   Updated: 2023/05/15 13:22:26 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_two(t_data *data)
{
	ft_sa(data);
}

void	ft_sort_three(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[0] < data->stack_a[2])
		ft_sa(data);
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] < data->stack_a[2])
		ft_ra(data);
	else if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[0] > data->stack_a[2])
		ft_rra(data);
	else if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[1] > data->stack_a[2])
	{
		ft_sa(data);
		ft_ra(data);
	}
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] > data->stack_a[2])
	{
		ft_sa(data);
		ft_rra(data);
	}
}

void	ft_find_smallest(t_data *data, t_datab *data_b)
{
	int	i;
	int	small;

	i = 0;
	small = 0;
	while (i < data->length - 1)
	{
		if (data->stack_a[small] < data->stack_a[i + 1])
			small = small;
		else
			small = i + 1;
		i++;
	}
	if (small > 0 && small < 2)
		ft_ra(data);
	if (small >= 2)
	{
		i = data->length - small;
		while (i-- > 0)
			ft_rra(data);
	}
	if (ft_check_if_sorted(data) == 2)
		return ;
	ft_pb(data, data_b);
}

void	ft_sort_little(t_data *data, t_datab *data_b)
{
	int	count;

	count = data->length - 3;
	while (count > 0)
	{
		ft_find_smallest(data, data_b);
		count--;
	}
	ft_sort_three(data);
	while (data_b->length > 0)
		ft_pa(data, data_b);
}
