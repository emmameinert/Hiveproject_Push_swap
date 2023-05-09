# include "pushswap.h"

void    ft_put_to_b(t_datab *data_b, t_data *data)
{
    int i;
    int *temp;

    temp = malloc(sizeof(int *)* (data_b->length));
    if (data_b->stack_b[0] == 0)
    {
        free(data_b->stack_b);
        ft_make_b_array(data_b);
        temp[0] = data->stack_a[0];
        data_b->stack_b[0] = temp[0];
    }
    else
    {
        i = -1;
        while (++i < data_b->length - 1)
            temp[i + 1] = data_b->stack_b[i];
        free(data_b->stack_b);
        ft_make_b_array(data_b);
        temp[0] = data->stack_a[0];
        i = -1;
        while (++i < data_b->length)
            data_b->stack_b[i] = temp[i];

    }
    //hier ist irgendiwe noch ne 0 am ende dran? ausser das kommt vom falschen printen
    free(temp);
}

void    ft_subtract(t_data *data)
{
    int *temp;
    int i;

    i = 0;
    if (data->length == 0)
        return ;
    temp = malloc(sizeof(int *)* (data->length));
    temp = ft_fill(temp, data->stack_a, data->length);
    free(data->stack_a);
    ft_make_array(data);
    while(i < data->length)
    {
        data->stack_a[i] = temp[i];
        i++;
    }
    free(temp);
}

void    ft_pb(t_data *data, t_datab *data_b)
{
    ft_printf("pb\n");
    if (!data->stack_a)
        return ;
    data_b->length++;
    ft_put_to_b(data_b, data);
    data->length--;
    ft_subtract(data);
}

void    ft_subtract_b(t_datab *data_b)
{
    int *temp;
    int i;

    i = 0;
    if (data_b->length == 0)
        return ;
    temp = malloc(sizeof(int *)* (data_b->length));
    temp = ft_fill(temp, data_b->stack_b, data_b->length);
    free(data_b->stack_b);
    ft_make_b_array(data_b);
    while(i < data_b->length)
    {
        data_b->stack_b[i] = temp[i];
        i++;
    }
    free(temp);
}

void    ft_pa(t_data *data, t_datab *data_b)
{
    ft_printf("pa\n");
    if (!data_b->stack_b)
        return ;
    data->length++;
    ft_put_to_a(data_b, data);
    data_b->length--;
    ft_subtract_b(data_b);
}

void    ft_put_to_a(t_datab *data_b, t_data *data)
{
    int i;
    int *temp;

    temp = malloc(sizeof(int *)* (data->length));
    if (data->stack_a[0] == 0)
    {
        free(data->stack_a);
        ft_make_array(data);
        temp[0] = data_b->stack_b[0];
        data->stack_a[0] = temp[0];
    }
    else
    {
        i = -1;
        while (++i < data->length - 1)
            temp[i + 1] = data->stack_a[i];
        free(data->stack_a);
        ft_make_array(data);
        temp[0] = data_b->stack_b[0];
        i = -1;
        while (++i < data->length)
            data->stack_a[i] = temp[i];

    }
    free(temp);
}
