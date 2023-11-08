/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:20:45 by emeinert          #+#    #+#             */
/*   Updated: 2023/05/18 11:47:34 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	ft_check_char(const char *str, int i, long sign, long result)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 2147483647)
			result = 0;
		result = result * 10 + (str[i] - '0');
		i++;
		if (sign * result > 2147483647)
			return (2147483648);
		if (sign * result < -2147483648)
			return (-21474836489);
	}
	return (sign * result);
}

long	ft_atol(const char *str)
{
	long	i;
	long	result;
	long	sign;

	result = 2147483648;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!ft_isdigit(str[i]))
			return (result);
	}
	result = ft_check_char(str, i, sign, result);
	return (result);
}
