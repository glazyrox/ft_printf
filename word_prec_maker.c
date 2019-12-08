/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_prec_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:10:03 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/08 14:52:57 by rgwayne-         ###   ########.fr       */
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
    add_to_list(str, buff_size, i + 1);
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
// выше функции для текста
char *start_by_len(t_struct *inform, char *buffer)
{
    char *str;
    
    str = ft_memalloc(inform->final_size + 1);
    ft_flags(str, inform, 0);
    ft_strcat(str, buffer);
    return (str);
}

char *start_by_prec(t_struct *inform, char *buffer, int len)
{
    char *str;
	int i;
	int g;

	g = 0;
	i = 0;
    str = ft_memalloc(inform->final_size + 1);
    if(ft_flags(str, inform, i))
    {
        i++;
        len--;
    }
    while (g < inform->precision - len)
    {
        str[i++] = 48;
        g++;
    }
    ft_strcat(str, buffer);
    return (str);
}