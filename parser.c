/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:23:18 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/26 20:45:02 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_modifiers(char *format, t_struct *inform)
{
    int i;

    i = 0;
    while(format[i++] != '\0')
    {
        if (format[i] == 'h')
        {
            if (format[i + 1] == 'h')
                inform->hh = 1;
            else
                inform->h = 1;
        }
        if (format[i] == 'l')
        {
            if (format[i + 1] == 'l')
                inform->ll = 1;
            else
                inform->l = 1;
        }
    }
    printf("\n TUT %d", inform->value);
    free(inform);
    //backslash(inform, format);
    return (0); 
}

int ft_width(t_struct *inform, char *format, int stop)
{
    int i;
    
    i = 0;
    while (format[i++])
    {
        if (format[i] >= 49 && format[i] <= 57)
            inform->width = ft_new_atoi(format, i, stop);
    }
    ft_modifiers(format, inform);
    return (0);
}

int ft_precision(t_struct *inform, char *format, int stop)
{
    int i;
    char *buff_format;

    buff_format = format;
    i = 0;
    while (i++ < stop)
    {
        if (buff_format[i++] == '.')
        {
            inform->zero = 0; // не точно, пока хотя бы так)
            inform->precision = ft_new_atoi(buff_format, i, stop);
            ft_width(inform, format, i--);
            return (0);
        }
    }
    ft_width(inform, format, stop);
    return (0);
}

int ft_flag(t_struct *inform, char *format, int stop)
{   
    int i;
    
    i = 0;
    while (i++ < stop)
    {
        if (format[i] >= 49 && format[i] <= 57)
        {
            inform->stopflags = 1;
            if (inform->stopflags == 1)
                break;
        }
        else if (format[i] == '+')
           inform->plus = 1; 
        else if (format[i] == '-')
            inform->plus = 1;   
        else if (format[i] == 32)
            inform->space = 1;
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
    inform = ft_memalloc(sizeof(t_struct));
    // if (!(inform = (t_struct*)malloc(sizeof(t_struct))))
    //     return(0);
    inform->size = 10;
    struct_zero(inform);
    while (format[i++])
    {
        if (format[i] == 'd' || format[i] == 'i') // отрефактори в функцию, если надо будет(скорее всего надо)
        {
            inform->type = 'd';
            inform->value = va_arg(list, int);
            ft_flag(inform, (char *)format, i);
            break;            
        }
    }
    return (0);
}