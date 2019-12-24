/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:00:41 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/24 14:51:40 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *p_value_maker(t_struct *infrom, char *buffer)
{
    char *str;

    str = ft_memalloc(infrom->final_size + 1);
    str[0] = 48;
    str[1] = 'x';
    ft_strcat(str, infrom->govno, infrom);
    return (str);
}

int ft_value_p(t_struct *inform, va_list list, int i)
{
    int len;
    char *str;
    // unsigned long long int pntr;
    
    len = 0;
    inform->value_d = va_arg(list, intptr_t);
    ft_hexer(inform, 0);
    str = hex_rev(inform);
    len = ft_strlen(str);
    inform->govno = str;
    return (len + 2);
}