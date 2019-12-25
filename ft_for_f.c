/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:56:33 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/25 20:03:48 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *f_value_maker(t_struct *infrom, char *buffer)
{
	return (infrom->govno);
}

int f_len(t_struct *inform)
{
	int len;

	len = 0;
	len = ft_strlen(inform->govno);
	if (inform->plus == 1 || inform->value_f < 0)
	{
		inform->value_is_neg = (inform->value_f < 0) ? 1 : 0;
		len += 1;
	}
	return (len);
}

int ft_value_f(t_struct *inform, va_list list, int i)
{
    int len;
	char *str;
	
	len = 0;
    inform->value_f = va_arg(list, double);
	inform->govno = ft_float(inform->value_f, inform);
	len = f_len(inform);
	return (len);
}