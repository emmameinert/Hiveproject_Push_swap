/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:19:31 by emeinert          #+#    #+#             */
/*   Updated: 2023/05/18 11:50:59 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_check_input(t_data *data, t_datab *data_b)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	flag = ft_check_doubles(data, data_b);
	if (flag == 1)
		ft_abort(data, data_b);
	flag = ft_check_if_sorted(data);
	if (flag == 2)
	{
		ft_free(data, data_b);
		exit(0);
	}
}

int	ft_check_doubles(t_data *data, t_datab *data_b)
{
	int	i;
	int	j;
	int	*temp;

	i = -1;
	j = -1;
	temp = ft_calloc(sizeof(int *), data->length);
	if (!temp)
		ft_abort(data, data_b);
	while (++i < data->length)
	{
		temp[i] = data->stack_a[i];
		while (j >= 0)
		{
			if (data->stack_a[i] == temp[j])
			{
				free(temp);
				return (1);
			}
			j--;
		}
		j = i;
	}
	free(temp);
	return (0);
}

int	ft_check_if_sorted(t_data *data)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (data->stack_a[0] < data->stack_a[1])
	{
		while ((i < data->length - 1)
			&& data->stack_a[i] < data->stack_a[i + 1])
		{
			i++;
			if (i == data->length - 1)
			{
				flag = 2;
				break ;
			}
		}
	}
	return (flag);
}

void	ft_fill_stack(t_data *data, t_datab *data_b, int k, int j)
{
	data->temp = ft_itoa(data->var);
	if (ft_strcmp(data->passed[j], data->temp) == 0)
		data->stack_a[k] = data->var;
	else
	{
		freemystuffchar(data->passed);
		ft_abort(data, data_b);
	}
	free(data->temp);
}
