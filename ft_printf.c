/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:28:40 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/21 19:53:58 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char ft_validator(char *string)
{

}

int ft_myprintf(const char *format, ...)
{
    t_printf p;

    ft_bzero(&p, sizeof(p));
    p.format = (char *)format;
    va_start(p.ap, 3);
    p.stack = va_arg(p.ap, char *); // не точно
    printf("%s", p.stack);
    p.stack = va_arg(p.ap, char *); 
    printf("%s", p.stack);
    p.stack = va_arg(p.ap, char *);
    printf("%d", p.stack);
    int a = 42;
    va_end (p.ap);
    return (0);
}