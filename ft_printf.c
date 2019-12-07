/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:28:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/07 20:00:29 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_text(char *format, int i, t_buff *buff_size)
{
    int g;
    char *str;
    
    g = 0;
    str = ft_memalloc(i + 2);
    while (g <= i)
    {
        str[g] = format[g];
        g++;
    }
    str[g] = '\0';
    buff_size->size_of_all += i;
    add_to_list(str, buff_size, i);
    return (0);
}

int not_arg_searcher(char *format, t_buff *buff_size)
{
    int i;

    i = 0;
    while (format[i + 1] != '%')
    {
        if (format[i + 1] == '\0')
            return (i);
        i++;
    }
    ft_text(format, i, buff_size);
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