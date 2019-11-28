/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:54 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/28 21:00:09 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PRINTF_H
#   define PRINTF_H

#   include <stdarg.h>
#   include "libft/includes/libft.h"
#   include <stdlib.h>
#   include <stdio.h>

#   define SIZE 500

typedef struct  s_struct
{
    int size;
    char type;
    int plus; //f
    int minus; //f
    int space; //f
    int sharp; //f
    int zero; //f
    int stopflags; // стоп флагов
    int width;
	int widthisneg; // ширина отрицательная
    int precision; // точность
    int value_d; // значение из стэка для d/i
    int h;
    int hh;
    int l;
    int ll;
    int format;
}               t_struct;

typedef struct s_buff
{
    size_t buff_size;
    va_list list;
}              t_buff;

int ft_printf(const char *format, ...);
char *ft_type(char *format, va_list list, t_buff *buff_size);
int ft_precision(t_struct *inform, char *format, int stop, t_buff *buff_size);
int	ft_new_atoi(const char *str, int start, int end);
int ft_width(t_struct *inform, char *format, int stop, int formodifiers, t_buff *buff_size);
int ft_modifiers(char *format, t_struct *inform, int stop, t_buff *buff_size);

int ft_value_maker(t_struct *inform, t_buff *buff_size);
int value_d(va_list list);

#endif
