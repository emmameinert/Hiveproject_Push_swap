# include "pushswap.h"

void    ft_check_input(t_data *data, t_datab *data_b)
{
    int flag;
    int i;

    flag = 0;
    i = 0;

    flag = ft_check_doubles(data);
    if (flag == 1)
        ft_abort(data, data_b);
    flag = ft_check_if_sorted(data);
    ft_printf("flag: %d\n", flag);
    if (flag == 2)
    {
        while (i < data->length)
        {
            ft_printf("        %d\n", data->stack_a[i]);
            i++;
        }
        ft_printf("---Stack_A---\n");// ---Stack_B---\n");
        exit(0);
    } //just return the already sorted stack
    flag = ft_check_if_rev_sorted(data);
    if (flag == 3)
    {
        return ;
        //reversed sorted
    }
}

int    ft_check_doubles(t_data *data)
{
    int *temp;
    int i;
    int j;

    j = -1;
    i = 0;
    temp =  ft_calloc(sizeof(int *), data->length);
    while (i <= data->length)
    {
        temp[i] = data->stack_a[i];
        while (j >= 0)
        {
            if (data->stack_a[i] == temp[j])
            {
                free(temp);
                return (1);
            }
            j--;
        }
        j = i;
        i++;
    }
    free(temp);
    return (0);
}
int ft_check_if_rev_sorted(t_data *data)
{
    int i;
    int flag;

    flag = 0;
    i = 0;
    if (data->stack_a[0] > data->stack_a[1])
    {
        while ((i < data->length - 1) && data->stack_a[i] > data->stack_a[i + 1])
        {
            i++;
            if (i + 1 == data->length)
            {
                ft_printf("Reversed sorted\n");
                return (3); //dann reversed sorted
            }
        }
    }
    return(0);
}


int    ft_check_if_sorted(t_data *data)
{
    int i;
    int flag;

    flag = 0;
    i = 0;
    if (data->stack_a[0] < data->stack_a[1])
    {
        while ((i < data->length - 1) && data->stack_a[i] < data->stack_a[i + 1])
        {
            i++;
            if (i == data->length - 1)
            {
                ft_printf("sorted\n");
                return (2); //dann sorted
            }
        }
    }
    return (flag);
}



//montag
//parsing finish cheeeck
//input check finish cheeeck

//dienstag
//fix input check cheeeck
//second struct  cheeeck
//fix pa, pb    cheeck
//write ra, rb operations   cheeck
//operations    cheeck

//Mittwoch
//write rra,  rrb operations    cheeck
// fix operations
//little sorting    cheeck
//small sort

//donnerstag
//check and catch up with the work

//wochenende
//radix sort

