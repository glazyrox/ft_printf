/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:28:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/09 20:30:22 by rgwayne-         ###   ########.fr       */
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
    buff_size->size_lists = SIZE;
    buff_size->flag = 1;
    while (*format)
    {
        if (*format == '%')
            format += ft_type((char *)format, list, buff_size);
        else
            format += not_arg_searcher((char *)format, buff_size);
        format++;
    }
    print_list(buff_size->p_head);
    va_end (list);
    return (0);
} 