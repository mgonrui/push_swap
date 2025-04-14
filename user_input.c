#include "push_swap.h"
#include <stdio.h>

char **input_is_in_quotes(int *argc, char **argv)
{

    if(*argc > 2)
    {
        ft_printf("error too many quotes");
        exit (1);
    }
    char **ret_value = ft_split(argv[1], ' ');
    *argc = 0;
    while (ret_value[*argc] != NULL)
        (*argc)++;
    return ret_value;
}

int input_is_outside_int_values(char *str)
{
   int sign;
   int i;
   long value;

   sign = 1;
   i = 0;
   value = 0;
   if (str[i] == '-' || str[i] == '+')
   {
       if (str[i] == '-')
           sign = -1;
       i++;
   }
   while (str[i] != '\0')
   {
       value *= 10;
       value += str[i] - '0';
       i++;
   }
   value *= sign;
   if (value > MAX_INT || value < MIN_INT)
       return 1;
   return 0;
}

int duplicate_foud(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[i] != NULL)
    {
        j = i + 1;
        while (argv[j] != NULL)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}
int sign_ok(char *str)
{
    int i;
    int j;
    int sign_count;
    sign_count = 0;
    i = 0;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
        {
            if (str[i] == '-' || str[i] == '+')
                i++;
            else
                return 0;
        }
        if (!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}
int input_is_wrong(char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i] != NULL)
    {
       j = 0;
       if (input_is_outside_int_values(argv[i]))
           return 1;
       if (!sign_ok(argv[i]))
           return 1;
       i++;
    }
    if (duplicate_foud(argv))
        return 1;
    return 0;
}
