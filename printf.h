/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:52:54 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/22 19:39:04 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#   ifndef PRINTF_H
#   define PRINTF_H

#   include <stdarg.h>
#   include <stdlib.h>
#   include <stdio.h>

#   define SIZE 10000

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
    intmax_t value_d; // значение из стэка для d/i
    unsigned char value_hex[25];
    int h;
    int hh;
    int l;
    int ll;
    int value_is_neg;
    int dack_prec;
    int null_for_c;
    char *govno;
	size_t final_size; // общий размер строки за одну обработку!
}               t_struct;

typedef struct s_buff
{
	size_t size_of_all; // каждый раз после обработки считаем сумму
    size_t previous_len; 
    size_t size_lists;
    int flag;
    int test;
}              t_buff;

int ft_printf(const char *format, ...);
int not_arg_searcher(char *format, t_buff *buff_size);
int ft_text(char *format, int i, t_buff *buff_size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
// парсер+-
void	*ft_memalloc(size_t size);
char	*ft_strcat(char *s1, const char *s2, t_struct *inform);
//
int ft_type(char *format, va_list list, t_buff *buff_size);
int ft_precision(t_struct *inform, char *format, int stop, t_buff *buff_size, va_list list);
int	ft_new_atoi(const char *str, int start, int end);
char		*ft_short_itoa(unsigned short int n);
int ft_width(t_struct *inform, char *format, int formodifiers, t_buff *buff_size, va_list list);
int ft_modifiers(char *format, t_struct *inform, int stop, t_buff *buff_size, va_list list);
void ft_make_arg(t_struct *inform, t_buff *buff_size, int len);
int ft_value_maker(t_struct *inform, t_buff *buff_size, va_list list);
int     ft_value_d(t_struct *inform, va_list list, int i); // для di
int ft_value_u(t_struct *inform, va_list list, int i); // для u
int int_len(long int value, t_struct *inform); // для diu
int ul_int_len(unsigned long int value, t_struct *inform); // для u
int us_int_len(unsigned short int value, t_struct *inform); // for short u
char *d_value_maker(t_struct *inform, char *buffer); // для di
char *u_value_maker(t_struct *inform, char *buffer); // для u
char *o_value_maker(t_struct *inform, char *buffer);
int ft_value_o(t_struct *inform, va_list list, int i); // для o
int ft_value_x(t_struct *inform, va_list list, int i);
char *word_maker(t_struct *inform, char *buffer, int len);
int va_value(t_struct *inform, va_list list, int i);
void ft_octal(t_struct *inform, int flag); // перевод в восьмиричную 
char		*ft_new_itoa(long int n);
// всякие itoa
char		*ft_long_itoa(unsigned long int n);
char	*ft_long_final(unsigned long int f);
char		*ft_oct_itoa(long n);
int	ft_long_len(unsigned long int f);
void ft_hexer(t_struct *inform, int i);
// обработка с ширины
char *ft_spacer_negative(char *s1, char sym, t_struct *inform);
char *start_by_width(t_struct *inform, char *buffer, int len);
char *start_by_neg_width(t_struct *inform, char *buffer, int len);
char *ft_negative_flags(char *str, t_struct *inform);
char *ft_spacer(char *s1, char sym, t_struct *inform, int len);
char *ft_flags(char *str, t_struct *inform, int i, int len);
char *ft_zeroes(char *s1, t_struct *inform, int len);
// обработка с точности
char *start_by_prec(t_struct *inform, char *buffer, int len);
// обработка с длины
char *start_by_len(t_struct *inform, char *buffer, int len);
// буффер
char	*ft_strfncat(char *s1, const char *s2, size_t n);
char	*ft_strfromcat(char *s1, const char *s2, size_t len, size_t n);
// hex
int hex_len(long int value, t_struct *inform);
char *hex_rev(t_struct *inform);
// с
char *x_value_maker(t_struct *inform, char *buffer);
int ft_diouxx(t_struct *inform, char sym);
int ft_csp(t_struct *inform, char sym);
int ft_value_c(t_struct *inform, va_list list, int i);
char *c_value_maker(t_struct *inform, char *buffer);
void flag_clear(t_struct *inform);
// s
int ft_value_s(t_struct *inform, va_list list, int i);
char *s_value_maker(t_struct *inform, char *buffer);
void ft_strflag_clear(t_struct *inform);
char *str_maker(t_struct *inform, char *buffer, int len);
#endif
