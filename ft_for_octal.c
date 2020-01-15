/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:32:14 by rgwayne-          #+#    #+#             */
/*   Updated: 2020/01/15 20:05:43 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_octal(t_struct *inform, int flag)
{
	int i;

	i = 0;
	if (flag == 3)
		inform->value_d = (unsigned short)inform->value_d;
	else if (flag == 4)
		inform->value_d = (unsigned char)inform->value_d;
	else if (flag == 5)
		inform->value_d = (unsigned int)inform->value_d;
	while (inform->value_d >= 8)
	{
		inform->value_hex[i] = inform->value_d % 8 + '0';
		inform->value_d /= 8;
		i++;
	}
	inform->value_hex[i] = inform->value_d + '0';
	inform->final_size += i + 1;
}

int		ft_value_o(t_struct *inform, va_list list, int i)
{
	if (i == 1)
		inform->value_d = va_arg(list, unsigned long);
	else if (i == 2)
		inform->value_d = va_arg(list, long long);
	else if (i == 3)
		inform->value_d = va_arg(list, unsigned int);
	else if (i == 4)
		inform->value_d = va_arg(list, int);
	if (i == 5)
		inform->value_d = va_arg(list, unsigned long long int);
	ft_octal(inform, i);
	return (hex_len(inform->value_d, inform));
}
