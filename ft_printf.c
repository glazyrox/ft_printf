/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:28:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/24 20:09:50 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_flag(t_struct *inform, char *format)
{
    printf("\nVALUE %d\n", (int)inform->value);
    free(inform);
    return (0);
}

int ft_type(char *format, va_list list)
{
    t_struct *inform;

    if (!(inform = (t_struct*)malloc(sizeof(t_struct))))
        return(0);
    inform->size = 10;
    struct_zero(inform);
    while (*format)
    {
        if (*format == 'd' || *format == 'i')
        {
            inform->type = 'd';
            inform->value = va_arg(list, int *);
            ft_flag(inform, format);
            break;            
        }
        format++;
    }
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list list;
    void *value;
    
    va_start(list, format);
    // int stack = va_arg(list, int *); // не точно
    while (*format)
    {
        if (*format == '%')
        {
            ft_type((char *)format, list);
        }
        format++;
    }
    va_end (list);
    return (0);
}