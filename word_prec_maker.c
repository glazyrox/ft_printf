/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_prec_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:10:03 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/06 15:56:21 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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