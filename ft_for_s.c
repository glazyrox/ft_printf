/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:38:38 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/22 20:13:08 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *str_maker(t_struct *inform, char *buffer, int len)
{
    
}

void ft_strflag_clear(t_struct *inform)
{
    inform->plus = 0;
    inform->space = 0;
    inform->sharp = 0;
    inform->dack_prec = 0;
}

char *s_value_maker(t_struct *inform, char *buffer)
{
    ft_strflag_clear(inform);
	return (inform->govno); 
}

int ft_value_s(t_struct *inform, va_list list, int i)
{
    int len;
    char *str;
    
    len = 0;
    str = va_arg(list, char *);
    //str = (!str) ? NULL : str; 
    str = (char *)str;
    len = ft_strlen(str);
    inform->govno = str;
    inform->final_size += len;
    return (len);
}