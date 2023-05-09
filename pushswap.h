
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include  "./sources/libft/libft.h"

typedef struct s_data
{
	int length;
    int *stack_a;

}   t_data;

typedef struct s_datab
{
    int length;
    int *stack_b;

}   t_datab;

t_data  *ft_make_data(void);
t_datab *ft_make_datab(void);

//parsing
void    ft_check_input(t_data *data, t_datab *data_b);
void    ft_convert(int argc, char **argv, t_data *data, t_datab *data_b);
void    ft_fill_array(char **argv, t_data *data, t_datab *data_b);
int     ft_check_doubles(t_data *data);
void    ft_count_chars(char **argv, t_data *data, t_datab *data_b);
int     ft_check_if_sorted(t_data *data);
int     ft_check_if_rev_sorted(t_data *data);

//freeing
void	freemystuffchar(char **str, int length);
void	ft_abort(t_data *data, t_datab *data_b);

//utils
long	ft_atol(const char *str);
void    ft_make_array(t_data *data);
void	ft_make_b_array(t_datab *data_b);
int    *ft_fill(int *str, int *ptr, int length);

//operations

void    ft_swap(int *a, int *b);
void    ft_sa(t_data *data);
void    ft_sb(t_datab *data_b);
void    ft_ss(t_data *data, t_datab *data_b);
void    ft_pa(t_data *data, t_datab *data_b);
void    ft_pb(t_data *data, t_datab *data_b);
void    ft_put_to_b(t_datab *data_b, t_data *data);
void    ft_put_to_a(t_datab *data_b, t_data *data);
void    ft_subtract(t_data *data);
void    ft_subtract_b(t_datab *data_b);
void    ft_rb(t_datab *data_b);
void    ft_ra(t_data *data);
void    ft_rr(t_data *data, t_datab *data_b);
void    ft_rra(t_data *data);
void    ft_rrb(t_datab *data_b);
void    ft_rrr(t_data *data, t_datab *data_b);

//sorting

void    ft_sort_two(t_data *data);
void    ft_sort_three(t_data *data);
void    ft_sort_little(t_data *data, t_datab *data_b);
#endif