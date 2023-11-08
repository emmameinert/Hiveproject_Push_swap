/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:58:32 by emeinert          #+#    #+#             */
/*   Updated: 2023/05/18 14:05:08 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_compare_num(t_data *data, t_datab *data_b, int k, int argc)
{
	int	j;

	j = 0;
	while (data->passed[j])
	{
		if (ft_is_number(data->passed[j]) == 1)
		{
			freemystuffchar(data->passed);
			ft_abort(data, data_b);
		}
		data->var = ft_atol(&(*data->passed[j]));
		if (data->var >= -2147483648 && data->var <= 2147483647)
		{
			ft_fill_stack(data, data_b, k, j);
			k++;
		}
		else
		{
			freemystuffchar(data->passed);
			ft_abort(data, data_b);
		}
		j++;
	}
	return (k);
}
