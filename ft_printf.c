/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:28:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/06 20:54:08 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int not_arg_searcher(char *format)
{
    int i;

    i = 0;
    while (format[i + 1] != '%')
    {
        if (format[i + 1] == '\0')
        {
            return (0);
        }
        i++;
    }
    printf("\n%s", format);
    return (i);
}

int ft_printf(const char *format, ...)
{
    va_list list;
    t_buff *buff_size;
    va_start(list, format);
    int i;

    i = 0;
    buff_size = ft_memalloc(sizeof(t_buff));
    buff_size->buff_size = 3;
    buff_size->govno = 1;
    while (*format)
    {
        if (*format == '%')
        {
            i = ft_type((char *)format, list, buff_size);
            format += i + 1;
        }
        else
        {
            i = not_arg_searcher((char *)format);
            format += i;
        }
        format++;
    }
    va_end (list);
    return (0);
} 