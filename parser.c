/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:23:18 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/08 13:29:58 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_modifiers(char *format, t_struct *inform, int stop, t_buff *buff_size, va_list list)
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
    ft_value_maker(inform, buff_size, list);
    return (0); 
}

int ft_width(t_struct *inform, char *format, int formodifiers, t_buff *buff_size, va_list list)
{
    int i;
    
    i = 0;
    while (i++ < inform->stop)
    {
        if (format[i] >= 49 && format[i] <= 57)
		{
			if (format[i - 1]  == '-'|| (inform->minus && inform->zero))
				inform->widthisneg = 1; // отрицательная ширина
            inform->width = ft_new_atoi(format, i, inform->stop);
            if (inform->width > 0)
                break;
		}
    }
    ft_modifiers(format, inform, formodifiers, buff_size, list);
    return (0);
}

int ft_precision(t_struct *inform, char *format, int stop, t_buff *buff_size, va_list list)
{
    int i;
    
    i = 0;
    while (i++ < stop)
    {
        if (format[i] == '.')
        {
            inform->zero = 0; // не точно, пока хотя бы так)
            inform->precision = ft_new_atoi(format, i + 1, stop);
            inform->stop = i;
            ft_width(inform, format, stop, buff_size, list);
            return (0);
        }
        inform->stop = i;
    }
    ft_width(inform, format, i, buff_size, list);
    return (0);
}

int ft_flag(t_struct *inform, char *format, int stop, t_buff *buff_size, va_list list)
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
            inform->minus = 1;   
        else if (format[i] == 32)
            inform->space = 1;
        else if (format[i] == 48)
            inform->zero = 1;
    }
    if (inform->plus)
        inform->space = 0;
    ft_precision(inform, format, stop, buff_size, list);
    return (0);
}

int ft_type(char *format, va_list list, t_buff *buff_size)
{
    int i;
    t_struct *inform;
    
    i = 0;
    inform = ft_memalloc(sizeof(t_struct));
    while (format[i++])
    {
        if (format[i] == 'd' || format[i] == 'i') // отрефактори в функцию, если надо будет (скорее всего надо)
        {
            inform->type = 'd';
            inform->format = 1;
            ft_flag(inform, (char *)format, i, buff_size, list);
            if (!(format[i + 1] == '\0'))
                return (i);
            break;
        }
        buff_size->struct_pointer++;
    }
    return (0);
}