/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:54 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/21 18:39:02 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_printf
{
    char *format;
    char *stack;
    char precision;
    int  long_precision;
    va_list ap;
}               t_printf;

int ft_myprintf(const char *format, ...);
char ft_validator(char *string);

#endif
