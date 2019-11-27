/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:23:18 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/27 20:42:28 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_modifiers(char *format, t_struct *inform, int stop, t_buff *buff_size)
{
    int i;

    i = 0;
    while(i < stop)
    {
        if (format[i] == 'h')
        {
            if (format[i + 1] == 'h')
            {
                inform->hh = 1;
                i++;
            }
            else
                inform->h = 1;
        }
        if (format[i] == 'l')
        {
            if (format[i + 1] == 'l')
            {
                inform->ll = 1;
                i++;
            }
            else
                inform->l = 1;
        }
        i++;
    }
    ft_maker(inform, buff_size);
    return (0); 
}

int ft_width(t_struct *inform, char *format, int stop, int formodifiers, t_buff *buff_size)
{
    int i;
    
    i = 0;
    while (i++ < stop)
    {
        if (format[i] >= 49 && format[i] <= 57)
            inform->width = ft_new_atoi(format, i, stop);
    }
    ft_modifiers(format, inform, formodifiers, buff_size);
    return (0);
}

int ft_precision(t_struct *inform, char *format, int stop, t_buff *buff_size)
{
    int i;
    
    i = 0;
    while (i++ < stop)
    {
        if (format[i] == '.')
        {
            inform->zero = 0; // не точно, пока хотя бы так)
            inform->precision = ft_new_atoi(format, i + 1, stop);
            ft_width(inform, format, i--, stop, buff_size);
            return (0);
        }
    }
    ft_width(inform, format, stop, i, buff_size);
    return (0);
}

int ft_flag(t_struct *inform, char *format, int stop, t_buff *buff_size)
{   
    int i;
    
    i = 0;
    while (i++ < stop)
    {
        if (format[i] >= 49 && format[i] <= 57)
        {
            inform->stopflags = 1;
            if (inform->stopflags == 1) // лол
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
    ft_precision(inform, format, stop, buff_size);
    return (0);
}

char *ft_type(char *format, va_list list, t_buff *buff_size)
{
    int i;
    t_struct *inform;
    
    i = 0;
    inform = ft_memalloc(sizeof(t_struct));
    while (format[i++])
    {
        if (format[i] == 'd' || format[i] == 'i') // отрефактори в функцию, если надо будет(скорее всего надо)
        {
            inform->type = 'd';
            inform->value = va_arg(list, int);
            inform->format = 1;
            ft_flag(inform, (char *)format, i, buff_size);
            break;       
        }
    }
    return (0);
}