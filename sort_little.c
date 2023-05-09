#include "pushswap.h"

void    ft_sort_two(t_data *data)
{
    ft_sa(data);
}

void    ft_sort_three(t_data *data)
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

void    ft_sort_little(t_data *data, t_datab *data_b)
{
    int count;
    int i;
    //look for smallest number first and then push
    i = 0;
    ft_printf("length: %d\n", data->length);
    count = data->length - 3;
    while (i++ < count)
        ft_pb(data, data_b);
    ft_sort_three(data);
    while (count > 0)
    {
        ft_printf("count: %d\n", count);
        if (data_b->stack_b[0] > data->stack_a[2])
        {
            ft_pa(data, data_b);
            ft_ra(data);
        }
        else if (data_b->stack_b[0] < data->stack_a[0])
            ft_pa(data, data_b);
        else if(data_b->stack_b[0] > data->stack_a[0] && data_b->stack_b[0] < data->stack_a[1])
        {
            ft_pa(data, data_b);
            ft_sa(data);
        }
        else if(data_b->stack_b[0] > data->stack_a[1] && data_b->stack_b[0] < data->stack_a[2])
        {
            ft_pb(data, data_b);
            ft_sb(data_b);
            ft_pa(data, data_b);
            ft_sa(data);
            ft_pa(data, data_b);
        }
        count--;
    }
}
