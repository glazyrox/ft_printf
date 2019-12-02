/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:28:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/02 14:54:54 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *format, ...)
{
    va_list list;
    t_buff *buff_size;
    va_start(list, format);
    
    buff_size = ft_memalloc(sizeof(t_buff));
    buff_size->buff_size = 3;
    buff_size->govno = 1;
    // int stack = va_arg(list, int *); // не точно
    while (*format)
    {
        if (*format == '%')
            ft_type((char *)format, list, buff_size);
        else
        {
            //write(1, format++, 1);
        }
        format++;
    }
    va_end (list);
    return (0);
} 