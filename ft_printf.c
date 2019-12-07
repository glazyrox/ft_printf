/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:28:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/07 20:11:35 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_printf(const char *format, ...)
{
    va_list list;
    t_buff *buff_size;
    va_start(list, format);
    int i;

    i = 0;
    buff_size = ft_memalloc(sizeof(t_buff));
    buff_size->flag = 1;
    printf("\n"); //
    while (*format)
    {
        if (*format == '%')
        {
            i = ft_type((char *)format, list, buff_size);
            format += i;
        }
        else
        {
            i = not_arg_searcher((char *)format, buff_size);
            format += i;
        }
        format++;
    }
    printf("%s", buff_size->p_begin->value);
    va_end (list);
    return (0);
} 