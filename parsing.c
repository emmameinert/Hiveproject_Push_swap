# include "pushswap.h"

void    ft_check_input(t_data *data)
{
    int flag;
    
    flag = 0;

    flag = ft_check_doubles(data);
    flag = ft_check_if_sorted(data);
    if (flag == 1)
        ft_abort(data);
    if (flag == 3)
    {
        return ;
        //reversed sorted
    }
    if (flag == 2)
        return ; //just return the already sorted stack
}

int    ft_check_doubles(t_data *data)
{
    int *temp;
    int i;
    int j;

    j = 0;
    i = 0;
    temp =  ft_calloc(sizeof(int *), data->length);
    while (i < data->length)
    {
        temp[i] = data->stack_a[i];
        while (j > 0)
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

int    ft_check_if_sorted(t_data *data)
{
    int i;
    int flag;

    flag = 0;
    i = 0;
    while (i < data->length - 1)
    {
        if (data->stack_a[i] > data->stack_a[i + 1])
        {
            flag = 2;
            while ((i < data->length - 1) && data->stack_a[i] > data->stack_a[i + 1])
            {
                i++;
                if (i == data->length)
                    flag = 3;
            }
        i++;
    }
    if (flag > 0)
        return (0);
    else 
        return (flag);
}



//montag
//parsing finish cheeeck
//input check finish cheeeck

//dienstag
//operations
//1-3 sorting

//Mittwoch
//operations
//little sorting

//donnerstag
//small sort

//freitag
//check and catch up with the work

//samstag+sonntag
//radix sort

