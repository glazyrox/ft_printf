/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:03:07 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/12 20:27:01 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *ft_zeroes(char *s1, t_struct *inform, int len)
{
    int i;

    i = 0;
    if (ft_flags(s1, inform, i))
        i++;
    else
        len++;
    // if (inform->value_is_neg)
    //     len += 1;
    while (i <= inform->width - len)
    {
        s1[i++] = '0';
    }
    return (s1);
}

char *ft_flags(char *str, t_struct *inform, int i)
{
    if (inform->value_is_neg)
    {
        if (inform->value_is_neg && inform->precision && !inform->zero)
            inform->final_size += 1;
		str[i] = '-';
        return (str);
    } 
    else if (inform->plus && !inform->value_is_neg)
    {
        str[i] = '+';
        return (str);
    }
    else if (!inform->plus && !inform->value_is_neg && inform->space)
    {
        if (!inform->width - i == i + inform->space)
        {
            str[i] = ' ';
            return (str);
        }
    }
    else if (!inform->plus && !inform->value_is_neg && inform->sharp)
    {
        str[i] = 48;
        return (str);
    }
    return (0);
}

char *ft_spacer(char *s1, char sym, t_struct *inform, int len)
{
    int i;

    i = 0;
    if (inform->precision > len)
    {
        while (i < inform->width - inform->precision)
        {
            s1[i++] = sym;
        }
        if (!ft_flags(s1, inform, i - 1))
            return (1);
    }
    else if (inform->width > len)
    {
        if (!inform->zero)
        {
            if ((inform->value_is_neg && inform->zero) || inform->plus)
                len++;
            while (i < inform->width - len)
                s1[i++] = sym;
            ft_flags(s1, inform, i);
        }
        else
            return (ft_zeroes(s1, inform, len));
    }
    return (0);
}

char *ft_spacer_negative(char *s1, char sym, t_struct *inform)
{
	size_t i;
	size_t g;

	i = 0;
	g = 0;
	while (s1[i])
		i++;
	s1[inform->final_size] = '\0';
	while (i < inform->final_size)
		s1[i++] = sym;
	return (s1);
}

char *ft_negative_flags(char *str, t_struct *inform)
{
    if (inform->value_is_neg)
    {
		str[0] = '-';
        return (str);
    } 
    else if (inform->plus && !inform->value_is_neg)
    {
        str[0] = '+';
        return (str);
    }
    else if (!inform->plus && !inform->value_is_neg && inform->space)
    {
        str[0] = ' ';
        return (str);
    }
    else if (inform->type == 'o' && inform->sharp)
    {
        str[0] = '0';
        return (str);
    }
    return (0);
}