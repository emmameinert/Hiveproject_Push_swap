# include "pushswap.h"

void    ft_ra(t_data *data)
{
    int vartemp;
    int *temp;
    int i;

    i = 0;
    temp = malloc(sizeof(int *)* (data->length));
    vartemp = data->stack_a[0];
    while (i < data->length - 1)
    {
        data->stack_a[i] = data->stack_a[i + 1];
        i++;
    }
    data->stack_a[i] = vartemp;
    free(temp);
    ft_printf("ra\n");
}

void    ft_rb(t_datab *data_b)
{
    int vartemp;
    int *temp;
    int i;

    i = -1;
    temp = malloc(sizeof(int *)* (data_b->length));
    vartemp = data_b->stack_b[0];
    while (i < data_b->length -1)
    {
        data_b->stack_b[i] = data_b->stack_b[i + 1];
        i++;
    }
    data_b->stack_b[i] = vartemp;
    free(temp);
    ft_printf("rb\n");  
}

void    ft_rr(t_data *data, t_datab *data_b)
{
    ft_ra(data);
    ft_rb(data_b);
    ft_printf("rr\n");   
}

//cover for less than 2 numbers