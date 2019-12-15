/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_int2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:14:59 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/15 16:00:48 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *o_value_maker(t_struct *inform, char *buffer)
{
	char *str;
    
    if (inform->h)
		str = ft_new_itoa((short)inform->value_d);
	else if (inform->hh)
		str = ft_new_itoa((char)inform->value_d);
	else if (inform->l)
		str = ft_long_itoa((long)inform->value_d);
	else if (inform->ll)
		str = ft_new_itoa((long long)inform->value_d);
	else
		str = ft_new_itoa(inform->value_d);
	return (str);
}

char *u_value_maker(t_struct *inform, char *buffer) // тут вписывать вэлью
{
    char *str;
    
    if (inform->h)
		str = ft_short_itoa((short)inform->value_d);
	else if (inform->hh)
		str = ft_new_itoa((unsigned char)inform->value_d);
	else if (inform->l)
		str = ft_long_itoa((long)inform->value_d);
	else if (inform->ll)
		str = ft_new_itoa((long long)inform->value_d);
	else
		str = ft_new_itoa(inform->value_d);
	return (str);
}

char *d_value_maker(t_struct *inform, char *buffer) // тут вписывать вэлью
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