/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_width_maker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:09:46 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/19 19:12:52 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *start_by_neg_width(t_struct *inform, char *buffer, int len) // функция для работы с отрицательной шириной
{
	char *str;
	int i;

	i = 0;
	str = ft_memalloc(inform->final_size + 1);
	if (ft_negative_flags(str, inform))
	{
		i++;
		len -= 2;
		if (inform->type == 'o')
			len += 1;
		else if ((inform->type == 'X' || inform->type == 'x') && inform->sharp)
		{
			i++;
			len -= 2;
		}
	}
	if (len < 0 && inform->type == 'o')
		len *= -1;
	if (len < 0)
		len = 0;
	if (inform->precision > len)
	{
		while (i < inform->precision - (len)) // т.к. на минус забиваем из-за конца строки
			str[i++] = '0';
	}
	ft_strcat(str, buffer, inform);
	ft_spacer_negative(str, ' ', inform);
	return (str);
}

char *start_by_width(t_struct *inform, char *buffer, int len) // функция для работы с положительной шириной
{
	char *str;
	int i;
	int g;

	g = 0;
	i = 0;
	if (inform->widthisneg)
		str = start_by_neg_width(inform, buffer, len);
	else
	{
		str = ft_memalloc(inform->final_size + 1);
		if (!(ft_spacer(str, ' ', inform, len)))
			len -= 1;
		while (str[i])
			i++;
		if (inform->precision >= len)
		{
			while (g < inform->precision - len)
			{
				str[i++] = 48;
				g++;
 			}
		}
		ft_strcat(str, buffer, inform);
	}
	return (str);
}

char *word_maker(t_struct *inform, char *buffer, int len) // тут разбив по ширине
{
	char *str;
	int i;

	i = 0;
	if (inform->width > inform->precision && inform->width > len)
		str = start_by_width(inform, buffer, len); // по ширине
	else if (inform->precision >= inform->width && inform->precision > len)
		str = start_by_prec(inform, buffer, len); // по точности
	else if (inform->precision <= len && inform->width <= len)
		str = start_by_len(inform, buffer, len);
	return (str);
}

char *value_maker(t_struct *inform, char *buffer) // тут вписывать вэлью
{
	char *str;
	
	if (inform->type == 'd')
		str = d_value_maker(inform, buffer);
	else if (inform->type == 'u')
		str = u_value_maker(inform, buffer);
	else if (inform->type == 'o')
		str = o_value_maker(inform, buffer);
	else if (inform->type == 'x' || inform->type == 'X')
		str = x_value_maker(inform, buffer);
	return (str);
}

void ft_make_arg(t_struct *inform, t_buff *buff_size, int len)
{	
	char *buffer;
	char *str;

	buffer = value_maker(inform, buffer); // buffer можно вообще не передавать же, отрефакторить
	str = word_maker(inform, buffer, len);
	write(1, str, inform->final_size);
	free(buffer);
	free(str);
}