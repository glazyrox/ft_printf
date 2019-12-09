/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_width_maker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:09:46 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/09 19:51:17 by rgwayne-         ###   ########.fr       */
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
	}
	if (inform->precision > len)
	{
		while (i < inform->precision - (len)) // т.к. на минус забиваем из-за конца строки
			str[i++] = 48;
	}
	ft_strcat(str, buffer);
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
		ft_strcat(str, buffer);
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
		str = start_by_len(inform, buffer);
	return (str);
}

char *value_maker(t_struct *inform, char *buffer) // тут вписывать вэлью
{
	char *str;
	
	if (inform->h)
		str = ft_new_itoa((short)inform->value_d);
	else if (inform->hh)
		str = ft_new_itoa((char)inform->value_d);
	else if (inform->l)
		str = ft_new_itoa((long)inform->value_d);
	else if (inform->ll)
		str = ft_new_itoa((long long)inform->value_d);
	else
		str = ft_new_itoa(inform->value_d);
	return (str);
}

void ft_make_arg(t_struct *inform, t_buff *buff_size, int len)
{	
	char *buffer;
	char *str;

	buffer = value_maker(inform, buffer); // buffer можно вообще не передавать же, отрефакторить
	str = word_maker(inform, buffer, len);
	//make_first_list(str, buff_size, inform->final_size + 1);
	write(1, str, ft_strlen(str));
	free(buffer);
}