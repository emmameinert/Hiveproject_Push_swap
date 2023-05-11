# include "pushswap.h"

void    ft_count_chars(char **argv, t_data *data, t_datab *data_b)
{
    int i;
    int j;
    char    **passed;
    char    **temp;

    i = 1;
    data->length = 0;
    while (argv[i] != '\0')
    {
        passed = ft_split(argv[i], ' ');
        if (!passed)
            ft_abort(data, data_b);
        j = 0;
        while (passed[j] != '\0')
            j++;
        data->length  += j;
        freemystuffchar(passed, j);
        i++;
    }
}

void    ft_fill_array(char **argv, t_data *data, t_datab *data_b)
{
    int i;
    int j;
    int k;
    char    **passed;
    char    *temp;

    i = 1;
    k = 0;
    while (argv[i] != '\0')
    {
        passed = ft_split(argv[i], ' ');
        if (!passed)
            ft_abort(data, data_b);
        j = -1;
        while (passed[++j])
        {   
            data->stack_a[k] = ft_atol(&(*passed[j]));
            temp = ft_itoa(data->stack_a[k]);
            if (ft_strcmp(passed[j], temp) != 0)
            { 
                freemystuffchar(passed, j);
                free(temp);
                ft_abort(data, data_b);
            }
            free(temp);
            k++;
        }
        freemystuffchar(passed, j);
        i++;
    }
}

void    ft_convert(int argc, char **argv, t_data *data, t_datab *data_b)
{
    ft_count_chars(argv, data, data_b);
    ft_make_array(data);
    ft_make_b_array(data_b);
    ft_fill_array(argv, data, data_b);
}

int main(int argc, char **argv)
{
    t_data *data;
    t_datab *data_b;
    int i;

    i = 0;
    if (argc < 2)
        exit(1);
    data = ft_make_data();
    data_b = ft_make_datab();
    ft_convert(argc, argv, data, data_b);
    ft_check_input(data, data_b);
    // while (i < data->length)
    // {
    //     ft_printf("%d\n", data->stack_a[i]);
    //     i++;
    // }
    if (data->length == 2)
        ft_sort_two(data);
    else if (data->length == 3)
        ft_sort_three(data);
    else if (data->length > 3 && data->length <= 5)
        ft_sort_little(data, data_b);
    i = 0;
    // i = 0;
    // if (data_b->length > 0)
    // {
    //     while (i < data_b->length)
    //     {
    //         ft_printf("            %d\n", data_b->stack_b[i]);
    //         i++;
    //     }
    // }
    if (data->length > 5)
        ft_sort_big_stack(data, data_b);
    // while (i < data->length)
    // {
    //     ft_printf("%d\n", data->stack_a[i]);
    //     i++;
    // }
   // ft_printf("---Stack_A---\n");// ---Stack_B---\n");
    if (data->stack_a)
		free(data->stack_a);
	if (data_b->stack_b)
		free(data_b->stack_b); //warum gibt das ein memory leak?
	if (data)
		free(data);
    if (data_b)
        free(data_b);
    return (0);
}

