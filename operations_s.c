# include "pushswap.h"

void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    ft_sa(t_data *data)
{
    if (!data->stack_a)
        return ;
    ft_swap(&data->stack_a[0], &data->stack_a[1]);
    ft_printf("sa\n"); //not print wenn called through ss?
}

void    ft_sb(t_datab *data_b)
{
    if (!data_b->stack_b)
        return ;
    ft_swap(&data_b->stack_b[0], &data_b->stack_b[1]);
    ft_printf("sb\n"); //not print wenn called through ss?
}

void    ft_ss(t_data *data, t_datab *data_b)
{
    ft_sa(data);
    ft_sb(data_b);
    ft_printf("ss\n");
}
