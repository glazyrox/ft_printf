/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:54 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/02 16:42:17 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PRINTF_H
#   define PRINTF_H

#   include <stdarg.h>
#   include "libft/includes/libft.h"
#   include <stdlib.h>
#   include <stdio.h>

#   define SIZE 500

typedef struct sNode{
    char value[5];
    struct sNode *next;
}              tNode;

typedef struct  s_struct
{
    char type;
    int stop; // костыль для парса
    int plus; //f
    int minus; //f
    int space; //f
    int sharp; //f
    int zero; //f
    int stopflags; // стоп флагов
    int width;
	int widthisneg; // ширина отрицательная
    int precision; // точность
    long long value_d; // значение из стэка для d/i
    int h;
    int hh;
    int l;
    int ll;
    int format;
	size_t final_size; // общий размер строки за одну обработку!
}               t_struct;

typedef struct s_buff
{
    size_t buff_size;
	size_t size_of_all; // каждый раз после обработки считаем сумму 
    tNode *p_begin; // листы для сохранения значений
    int govno;
}              t_buff;

int ft_printf(const char *format, ...);
char *ft_type(char *format, va_list list, t_buff *buff_size);
int ft_precision(t_struct *inform, char *format, int stop, t_buff *buff_size, va_list list);
int	ft_new_atoi(const char *str, int start, int end);
int ft_width(t_struct *inform, char *format, int formodifiers, t_buff *buff_size, va_list list);
int ft_modifiers(char *format, t_struct *inform, int stop, t_buff *buff_size, va_list list);
void ft_make_arg(t_struct *inform, t_buff *buff_size);
int ft_value_maker(t_struct *inform, t_buff *buff_size, va_list list);
int va_value(t_struct *inform, va_list list, int i);
int value_d(va_list list);
tNode* ft_create_list(int N);

#endif
