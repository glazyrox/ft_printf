/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:54 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/08 14:47:20 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PRINTF_H
#   define PRINTF_H

#   include <stdarg.h>
#   include "libft/includes/libft.h"
#   include <stdlib.h>
#   include <stdio.h>

#   define SIZE 500

typedef struct sNode {
    char value[1000];
    struct sNode *next;
    int count;
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
    int value_is_neg;
	size_t final_size; // общий размер строки за одну обработку!
}               t_struct;

typedef struct s_buff
{
	size_t size_of_all; // каждый раз после обработки считаем сумму 
    tNode *p_begin; // листы для сохранения значений
    int struct_pointer;
    int flag;
    int test;
}              t_buff;

int ft_printf(const char *format, ...);
int not_arg_searcher(char *format, t_buff *buff_size);
int ft_text(char *format, int i, t_buff *buff_size);
// парсер+-
int ft_type(char *format, va_list list, t_buff *buff_size);
int ft_precision(t_struct *inform, char *format, int stop, t_buff *buff_size, va_list list);
int	ft_new_atoi(const char *str, int start, int end);
int ft_width(t_struct *inform, char *format, int formodifiers, t_buff *buff_size, va_list list);
int ft_modifiers(char *format, t_struct *inform, int stop, t_buff *buff_size, va_list list);
void ft_make_arg(t_struct *inform, t_buff *buff_size, int len);
int ft_value_maker(t_struct *inform, t_buff *buff_size, va_list list);
char *word_maker(t_struct *inform, char *buffer, int len);
int va_value(t_struct *inform, va_list list, int i);
tNode* ft_create_list(int N);
char		*ft_new_itoa(int n);
// обработка с ширины
char *ft_spacer_negative(char *s1, char sym, t_struct *inform);
char *start_by_width(t_struct *inform, char *buffer, int len);
char *start_by_neg_width(t_struct *inform, char *buffer, int len);
char *ft_negative_flags(char *str, t_struct *inform);
char *ft_spacer(char *s1, char sym, t_struct *inform, int len);
char *ft_flags(char *str, t_struct *inform, int i);
char *ft_zeroes(char *s1, t_struct *inform, int len);
// обработка с точности
char *start_by_prec(t_struct *inform, char *buffer, int len);
// обработка с длины
char *start_by_len(t_struct *inform, char *buffer);
// буффер
void add_to_list(char *str, t_buff *buff_size, size_t len);

#endif
