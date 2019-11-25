/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:54 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/25 20:24:14 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include "libft/includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_struct
{
    int size;
    char type;
    int plus;
    int minus;
    int space;
    int sharp;
    int zero;
    int width;
    int precision; // точность
    void *value; // значение из стэка
}               t_struct;

int ft_printf(const char *format, ...);
int ft_type(char *format, va_list list);
void struct_zero(t_struct *inform);
int ft_precision(t_struct *inform, char *format, int stop);
int	ft_new_atoi(const char *str, int start, int end);

#endif
