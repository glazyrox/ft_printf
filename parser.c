/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:23:18 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/26 15:45:43 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_width(t_struct *inform)
{
    free(inform); 
    return (0);
}

int ft_precision(t_struct *inform, char *format, int stop)
{
    int i;

    i = 0;
    while (i++ < stop)
    {
        if (format[i++] == '.')
        {
            inform->precision = ft_new_atoi(format, i, stop);
            break;
        }
    }
    ft_width(inform);
    return (0);
}

int ft_flag(t_struct *inform, char *format, int stop)
{   
    int i;
    
    i = 0;
    while (i++ < stop)
    {
        if (format[i] == '+')
           inform->plus = 1; 
        else if (format[i] == '-')
            inform->plus = 1;   
        else if (format[i] == 32)
            inform->space = 1;
        else if
        else if (format[i] == 48)
            inform->zero = 1;
    }
    ft_precision(inform, format, stop);
    return (0);
}

int ft_type(char *format, va_list list)
{
    t_struct *inform;
    int i;
    
    i = 0;
    if (!(inform = (t_struct*)malloc(sizeof(t_struct))))
        return(0);
    inform->size = 10;
    struct_zero(inform);
    while (format[i++])
    {
        if (format[i] == 'd' || format[i] == 'i') // отрефактори в функцию
        {
            inform->type = 'd';
            inform->value = va_arg(list, int *);
            ft_flag(inform, (char *)format, i);
            break;            
        }
    }
    return (0);
}