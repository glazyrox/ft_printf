/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:09:46 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/04 20:58:52 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// void ft_list_maker(char *buffer, t_struct *inform, t_buff *buff_size) // тут будет буффер
// {
// 	int len;
// 	int len_word;

// 	len = sizeof(buff_size->p_begin->value);
// 	len_word = ft_strlen(buffer);
// 	// if (len < len_word)
// 	// {
// 	// 	while (len_word > 0)
// 	// 	ft_strncpy(buff_size->p_begin->value, buffer, len - 1);
// 	// }	
// }

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

char *word_maker(t_struct *inform, char *buffer, int len) // тут расставлять флаги
{
	char *str;
	int i;

	i = 0;
	if (!(str = malloc(sizeof(char) * inform->final_size + 1)))
		return (0);
	if (inform->value_is_neg)
	{
		str[i++] = '-';
		len--;
	}
	if (inform->plus && !(inform->value_is_neg))
	{
		str[i++] = '+';
		len -= 2;
	}
	if (inform->precision > len)
	{
		if (!inform->value_is_neg)
			inform->precision -= 1;
		while (i <= inform->precision - (len)) // т.к. на минус забиваем из-за конца строки
			str[i++] = 48;
	}
	ft_strcat(str, buffer);
	ft_spacer(str, ' ', inform, 1, len);
	printf("%s\n", str);
}

void ft_make_arg(t_struct *inform, t_buff *buff_size, int len)
{	
	char *buffer;
	buffer = value_maker(inform, buffer);
	if (inform->width > inform->precision && inform->widthisneg)
	{
		word_maker(inform, buffer, len);
	}
	//ft_list_maker(buffer, inform, buff_size);
	//free(buffer);
}