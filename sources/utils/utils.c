/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:55:29 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 13:59:14 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswap.h"

int	*ft_fill(int *str, int *ptr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		str[i] = ptr[i + 1];
		i++;
	}
	return (str);
}

void	freemystuffchar(char **str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_abort(t_data *data, t_datab *data_b)
{
	ft_free(data, data_b);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	ft_free(t_data *data, t_datab *data_b)
{
	if (data->stack_a)
		free(data->stack_a);
	if (data_b->stack_b)
		free(data_b->stack_b);
	if (data)
		free(data);
	if (data_b)
		free(data_b);
}

void	ft_exit_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
