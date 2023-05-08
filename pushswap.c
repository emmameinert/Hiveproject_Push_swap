# include "pushswap.h"

void    ft_count_chars(char **argv, t_data *data)
{
    int i;
    int j;

    i = 1;

    data->length = 0;
    char    **passed;
    char    **temp;
    while (argv[i] != '\0')
    {
        passed = ft_split(argv[i], ' ');
        if (!passed)
            ft_abort(data);
        j = 0;
        while (passed[j] != '\0')
            j++;
        data->length  += j;
        freemystuffchar(passed, j);
        i++;
    }
}

void    ft_fill_array(char **argv, t_data *data)
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
            ft_abort(data);
        j = -1;
        while (passed[++j])
        {   
            data->stack_a[k] = ft_atol(&(*passed[j]));
            temp = ft_itoa(data->stack_a[k]);
            if (ft_strcmp(passed[j], temp) != 0)
            { 
                freemystuffchar(passed, j);
                free(temp);
                ft_abort(data);
            }
            free(temp);
            k++;
        }
        freemystuffchar(passed, j);
        i++;
    }
}

void    ft_convert(int argc, char **argv, t_data *data)
{
    ft_count_chars(argv, data);
    ft_make_array(data);
    ft_fill_array(argv, data);
}

int main(int argc, char **argv)
{
    t_data *data;
    
    int i;

    i = 0;
    if (argc < 2)
        exit(1);
    data = ft_make_data();
    ft_convert(argc, argv, data);
    ft_check_input(data);
    while (i < data->length)
    {
        ft_printf("        %d \n", data->stack_a[i]);
        i++;
    }
    ft_printf("-----Stack_A-----\n");
    //sort small amount (<=10)
    //sort big amount (>10)
    if (data->stack_a)
		free(data->stack_a);
	// if (data->stack_b)
	// 	free(data->stack_b);
	if (data)
		free(data);
    return (0);
}

