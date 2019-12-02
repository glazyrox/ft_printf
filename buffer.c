/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:09:46 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/02 18:59:13 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_list_maker(char *buffer, t_struct *inform, t_buff *buff_size)
{
	int len;
	int len_word;

	len = sizeof(buff_size->p_begin->value);
	len_word = ft_strlen(buffer);
	// if (len < len_word)
	// {
	// 	while (len_word > 0)
	// 	ft_strncpy(buff_size->p_begin->value, buffer, len - 1);
	// }	
}

char *arg_maker(t_struct *inform, char *buffer)
{
	char *str;
	char *str1;
	
	if (!(str = malloc(sizeof(char) * inform->final_size + 1)))
		return (0);
	if (inform->h)
		str = ft_itoa((short)inform->value_d);
	else if (inform->hh)
		str = ft_itoa((char)inform->value_d);
	else if (inform->l)
		str = ft_itoa((long)inform->value_d);
	else if (inform->ll)
		str = ft_itoa((long long)inform->value_d);
	else
		str = ft_itoa((long long)inform->value_d);
	return (str);
}

void ft_make_arg(t_struct *inform, t_buff *buff_size)
{	
	char *buffer;
	
	buffer = arg_maker(inform, buffer);
	//ft_list_maker(buffer, inform, buff_size);
	printf("\nVALUE %d", buff_size->size_of_all);
	free(buffer);
}