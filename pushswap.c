/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:28:14 by emeinert          #+#    #+#             */
/*   Updated: 2023/05/18 14:04:23 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_count_chars(char **argv, t_data *data, t_datab *data_b)
{
	int		i;
	int		j;
	char	**passed;
	char	**temp;

	i = 1;
	data->length = 0;
	if (argv[1] == NULL)
		ft_abort(data, data_b);
	while (argv[i] != '\0')
	{
		passed = ft_split(argv[i], ' ');
		if (!passed)
			ft_abort(data, data_b);
		j = 0;
		while (passed[j] != '\0')
			j++;
		data->length += j;
		freemystuffchar(passed);
		i++;
	}
}

void	ft_fill_array(char **argv, t_data *data, t_datab *data_b, int argc)
{
	int	i;
	int	k;

	k = 0;
	i = 1;
	while (argv[i] != '\0')
	{
		data->passed = ft_split(argv[i], ' ');
		if (!data->passed)
			ft_abort(data, data_b);
		k = ft_compare_num(data, data_b, k, argc);
		freemystuffchar(data->passed);
		i++;
	}
}

void	ft_convert(int argc, char **argv, t_data *data, t_datab *data_b)
{
	ft_count_chars(argv, data, data_b);
	ft_make_array(data, data_b);
	ft_make_b_array(data, data_b);
	ft_fill_array(argv, data, data_b, argc);
	ft_check_input(data, data_b);
}

void	ft_check_amount(t_data *data, t_datab *data_b)
{
	if (data->length == 2)
		ft_sort_two(data);
	else if (data->length == 3)
		ft_sort_three(data);
	else if (data->length > 3 && data->length <= 5)
		ft_sort_little(data, data_b);
	else if (data->length > 5)
		ft_sort_big_stack(data, data_b);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_datab	*data_b;
	int		i;

	i = 1;
	if (argc < 2)
		exit(0);
	if (argv[1][0] == '\0')
		ft_exit_error();
	data = ft_make_data();
	data_b = ft_make_datab(data);
	ft_convert(argc, argv, data, data_b);
	ft_check_amount(data, data_b);
	ft_free(data, data_b);
	return (0);
}
