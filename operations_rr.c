# include "pushswap.h"

void    ft_rra(t_data *data)
{
    int vartemp;
    int *temp;
    int i;

    temp = malloc(sizeof(int *)* (data->length));
    i = 0;
    vartemp = data->stack_a[data->length - 1];
    while (i < data->length)
    {
        temp[i] = data->stack_a[i];
        i++;
    }
    i = 1;
    data->stack_a[0] = vartemp;
    while (i < data->length)
    {
        data->stack_a[i] = temp[i - 1];
        i++;
    }
    free(temp);
    ft_printf("rra\n");
}

void    ft_rrb(t_datab *data_b)
{
    int vartemp;
    int *temp;
    int i;

    temp = malloc(sizeof(int *)* (data_b->length));
    i = 0;
    vartemp = data_b->stack_b[data_b->length - 1];
    while (i < data_b->length)
    {
        temp[i] = data_b->stack_b[i];
        i++;
    }
    i = 1;
    data_b->stack_b[0] = vartemp;
    while (i < data_b->length)
    {
        data_b->stack_b[i] = temp[i - 1];
        i++;
    }
    free(temp);
    ft_printf("rrb\n");
}

void    ft_rrr(t_data *data, t_datab *data_b)
{
    ft_rra(data);
    ft_rrb(data_b);
    ft_printf("rrr\n");
}
