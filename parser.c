/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:23:18 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/24 15:46:42 by rgwayne-         ###   ########.fr       */
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
			if (format[i - 1]  == '-'|| (inform->minus && inform->zero) || (inform->minus && inform->plus))
				inform->widthisneg = 1; // отрицательная ширина
            if (inform->type == 'o' && inform->minus)
                inform->widthisneg = 1;
            if (inform->widthisneg)
                inform->zero = 0;
            inform->width = ft_new_atoi(format, i, inform->stop);
            if (inform->width > 0)
                break;
		}
    }
    if (inform->precision > inform->width)
        inform->zero = 0;
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
            inform->precision = ft_new_atoi(format, i + 1, stop);
            if (inform->precision == 0)
                inform->dack_prec = 2;
            inform->zero = (inform->type == 's' && inform->zero) ? 1 : 0;
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
            break;
        else if (format[i] == '+' && inform->type != 'u')
           inform->plus = 1; 
        else if (format[i] == '-')
            inform->minus = 1;   
        else if (format[i] == 32 && inform->type != 'u')
            inform->space = 1;
        else if (format[i] == 48)
            inform->zero = 1;
        else if (format[i] == 35 && inform->type != 'd')
            inform->sharp = 1;
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
        if (ft_diouxx(inform, format[i])) // отрефактори в функцию потом
        {
            ft_flag(inform, (char *)format, i, buff_size, list);
            if (!(format[i + 1] == '\0'))
            {
                buff_size->test = 1;
                return (i);
            }
            if (format[i + 1] == '\0')
                return (i);
            break;
        }
    }
    return (0);
}