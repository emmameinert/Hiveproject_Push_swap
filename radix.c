# include "pushswap.h"

void    ft_sort(int *a, int len)
{
    int i;
    int step;

    i = 0;
    step = i + 1;
    while(step < len)
    {
        if (a[i] > a[step])
            ft_swap(&a[i], &a[step]);
        i++;
        step++;
    }
    len--;
    if (len > 0)
        ft_sort(a, len);
}

void    ft_convert_for_radix(t_data *data)
{
    int i;
    int j;
    int *cpy;

    i = -1;
    cpy = malloc(sizeof(int *)* (data->length));
	if (!cpy)
	{
		free(data); //fehlt noch was
		exit(1);
	}
    while (++i < data->length)
        cpy[i] = data->stack_a[i];
    ft_sort(cpy, data->length);
    i = -1;
    while (++i < data->length)
    {
        j = -1;
        while (++j < data->length)
        {
            if (data->stack_a[i] == cpy[j])
            {
                data->stack_a[i] = j + 1;
                break ;
            }
        }
    }
    i = 0;
    // while (i < data->length)
    // {
    //     ft_printf("cpy[j]:  %d A[j]:    %d\n", cpy[i], data->stack_a[i]);
    //     i++;
    // }
    // ft_printf("---Stack_A---\n");// ---Stack_B---\n");
    data->bits = ft_binary(cpy[data->length - 1]); //max bits
}

int    ft_binary(int n)
{
    int i;
    int temp;
    i = 0;
    //ft_printf("n: %d\n", n);
    while (n > 0)
    {
        //ft_printf("i: %d\n", i);
        temp = n % 2;
        n = n/2; 
        i++;
    }
    return(i);
}

void    ft_radix(t_data *data, t_datab *data_b)
{
    int i;
    int count;
    int bits;
    bits = 0;
    // ft_printf("bits %d\n", data->bits);
    // ft_printf("length: %d\n", data->length);
    // ft_printf("1. number: %d\n", data->stack_a[0]); 
    // ft_printf("bithsifting: %d\n", (data->stack_a[0]>>bits & 1));
    while (bits < data->bits) //ft_check_if_sorted(data) != 2)
    {
        count = data->length;
        while (count > 0)
        {
            //ft_printf("count: %d\n", count);
            if ((data->stack_a[0] >> bits & 1) == 0)
                ft_pb(data, data_b);
            else if ((data->stack_a[0] >> bits & 1) == 1)
                ft_ra(data);
            //ft_printf("1. number: %d\n", data->stack_a[0]);
            count--;
        }
        //ft_printf("length: %d\n", data_b->length);
        while (data_b->length > 0)
            ft_pa(data, data_b);
        bits++;
    }
}

void    ft_sort_big_stack(t_data *data, t_datab *data_b)
{
    ft_convert_for_radix(data);
    ft_radix(data, data_b);
}

