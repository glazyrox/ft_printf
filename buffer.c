/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:09:46 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/30 17:57:00 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *arg_maker(t_struct *inform, char *buffer)
{
	char *str;
	char *str1;
	
	if (!(str = malloc(sizeof(char) * inform->final_size)))
		return (0);
	if (inform->h)
		str = ft_itoa((short)inform->value_d);
	else if (inform->hh)
		str = ft_itoa((signed)inform->value_d);
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

	if (buff_size->size_of_all > 100 || buff_size->govno == 1)
		buff_size->p_begin = ft_create_list(1);
	buffer = arg_maker(inform, buffer);
	if (buff_size->govno)
	{
		ft_strcpy(buff_size->p_begin->value, buffer);
		buff_size->govno = 0;
	}
	else
		ft_strncat(buff_size->p_begin->value, buffer, inform->final_size);
	free(buffer);
}