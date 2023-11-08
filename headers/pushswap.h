/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:37:25 by emeinert          #+#    #+#             */
/*   Updated: 2023/11/08 14:03:24 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include  "../sources/libft/libft.h"

typedef struct s_data
{
	int		length;
	int		*stack_a;
	int		bits;
	long	var;
	int		*cpy;
	char	**passed;
	char	*temp;
}	t_data;

typedef struct s_datab
{
	int	length;
	int	*stack_b;

}	t_datab;

t_data	*ft_make_data(void);
t_datab	*ft_make_datab(t_data *data);

//parsing
void	ft_check_input(t_data *data, t_datab *data_b);
void	ft_convert(int argc, char **argv, t_data *data, t_datab *data_b);
void	ft_fill_array(char **argv, t_data *data, t_datab *data_b, int argc);
int		ft_check_doubles(t_data *data, t_datab *data_b);
void	ft_count_chars(char **argv, t_data *data, t_datab *data_b);
int		ft_check_if_sorted(t_data *data);
void	ft_check_amount(t_data *data, t_datab *data_b);
void	ft_fill_stack(t_data *data, t_datab *data_b, int k, int j);
int		ft_compare_num(t_data *data, t_datab *data_b, int k, int argc);
int		ft_is_number(char *str);

//freeing
void	freemystuffchar(char **str);
void	ft_abort(t_data *data, t_datab *data_b);
void	ft_free(t_data *data, t_datab *data_b);
void	ft_exit_error(void);

//utils
long	ft_check_char(const char *str, int i, long sign, long result);
long	ft_atol(const char *str);
void	ft_make_array(t_data *data, t_datab *data_b);
void	ft_make_b_array(t_data *data, t_datab *data_b);
int		*ft_fill(int *str, int *ptr, int length);
int		*ft_make_temp(t_data *data, t_datab *data_b, int len);

//operations

void	ft_swap(int *a, int *b);
void	ft_sa(t_data *data);
void	ft_sb(t_datab *data_b);
void	ft_pa(t_data *data, t_datab *data_b);
void	ft_pb(t_data *data, t_datab *data_b);
void	ft_put_to_b(t_datab *data_b, t_data *data);
void	ft_put_to_a(t_datab *data_b, t_data *data);
void	ft_subtract(t_data *data, t_datab *data_b);
void	ft_subtract_b(t_data *data, t_datab *data_b);
void	ft_rb(t_datab *data_b);
void	ft_ra(t_data *data);
void	ft_rra(t_data *data);
void	ft_rrb(t_datab *data_b);

//sorting

void	ft_sort_two(t_data *data);
void	ft_sort_three(t_data *data);
void	ft_sort_little(t_data *data, t_datab *data_b);
void	ft_find_smallest(t_data *data, t_datab *data_b);

//radix sorting

void	ft_convert_for_radix(t_data *data, t_datab *data_b);
void	ft_sort(int *a, int len);
int		ft_binary(int n);
void	ft_radix(t_data *data, t_datab *data_b);
void	ft_sort_big_stack(t_data *data, t_datab *data_b);

#endif
