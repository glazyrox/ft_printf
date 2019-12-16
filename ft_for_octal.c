/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:56:48 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/16 19:45:18 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_octal(t_struct *inform)
{
    unsigned long int nbr;
    unsigned long int rev_nbr;
    unsigned long int test;

    test = inform->value_d;
    nbr = 0;
    rev_nbr = 0;
    while (inform->value_d > 8)
    {
        rev_nbr = rev_nbr * 10 + inform->value_d % 8;
        inform->value_d /= 8;
    }
    rev_nbr = rev_nbr * 10 + inform->value_d;
    while (rev_nbr)
    {
        nbr = nbr * 10 + rev_nbr % 10;
        rev_nbr /= 10;
    }
    inform->value_d = nbr;
    if (test > inform->value_d)
        inform->value_d *= 10;
}

int ft_value_o(t_struct *inform, va_list list, int i)
{
    int len;

    len = 0;
    if (i == 1)
    {
    	inform->value_d = va_arg(list, unsigned long);
        ft_octal(inform);
		len = int_len(inform->value_d, inform);
    }
	else if (i == 2)
    {
        inform->value_d = va_arg(list, unsigned long);
        ft_octal(inform);
		len = ul_int_len(inform->value_d, inform);
    }
	else if (i == 3)
    {
        inform->value_d = va_arg(list, unsigned int);
        ft_octal(inform);
		len = ul_int_len((short)inform->value_d, inform);
    }
	else if (i == 4)
    {
        inform->value_d = va_arg(list, unsigned int);
        ft_octal(inform);
		len = ul_int_len((char)inform->value_d, inform);
    }
	if (i == 5)
    {
        inform->value_d = va_arg(list, unsigned int);
        ft_octal(inform);
		len = int_len(inform->value_d, inform);
    }
    return (len);
}