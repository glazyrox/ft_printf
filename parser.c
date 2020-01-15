/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:44:25 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/15 21:25:41 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_modifiers(char *format, t_struct *inform, t_buff\
								*buff_size, va_list list)
{
	int i;

	i = -1;
	while (++i < inform->givup)
	{
		if (format[i] == 'h')
		{
			if (format[i++ + 1] == 'h')
				inform->hh = 1;
			else
				inform->h = 1;
		}
		if (format[i] == 'l' || format[i] == 'L')
		{
			if (format[i++ + 1] == 'l')
				inform->ll = 1;
			else
				inform->l = 1;
		}
	}
	ft_value_maker(inform, buff_size, list);
	return (0);
}

int	ft_width(t_struct *inform, char *format, t_buff *buff_size, va_list list)
{
	int i;

	i = 0;
	while (i++ < inform->stop)
	{
		if (format[i] >= 49 && format[i] <= 57)
		{
			if (format[i - 1] == '-' || (inform->minus && inform->zero)\
										|| (inform->minus && inform->plus))
				inform->widthisneg = 1;
			if ((inform->type == 'o' || inform->type == 'f') && inform->minus)
				inform->widthisneg = 1;
			if (inform->widthisneg)
				inform->zero = 0;
			inform->width = ft_new_atoi(format, i, inform->stop);
			if (inform->width > 0)
				break ;
		}
	}
	if (inform->precision > inform->width)
		inform->zero = 0;
	ft_modifiers(format, inform, buff_size, list);
	return (0);
}

int	ft_precision(t_struct *inform, char *format,\
					t_buff *buff_size, va_list list)
{
	inform->givup = 0;
	while (inform->givup++ < inform->fuckup)
	{
		if (format[inform->givup] == '.')
		{
			inform->precision = ft_new_atoi(format,\
					inform->givup + 1, inform->fuckup);
			if (inform->precision == 0)
				inform->dack_prec = 2;
			inform->zero = ((inform->type == 's' || inform->type == 'f')\
													&& inform->zero) ? 1 : 0;
			inform->stop = inform->givup;
			inform->givup = inform->fuckup;
			ft_width(inform, format, buff_size, list);
			return (0);
		}
		inform->stop = inform->givup;
	}
	ft_width(inform, format, buff_size, list);
	return (0);
}

int	ft_flag(t_struct *inform, char *format, t_buff *buff_size, va_list list)
{
	int i;

	i = 0;
	while (i++ < inform->fuckup)
	{
		if (format[i] >= 49 && format[i] <= 57)
			break ;
		else if (format[i] == '+' && inform->type != 'u')
			inform->plus = 1;
		else if (format[i] == '-')
			inform->minus = 1;
		else if (format[i] == 32 && inform->type != 'u')
			inform->space = 1;
		else if (format[i] == 48)
			inform->zero = 1;
		else if (format[i] == 35 && inform->type != 'd')
			inform->sharp = 1;
	}
	if (inform->plus)
		inform->space = 0;
	ft_precision(inform, format, buff_size, list);
	return (0);
}

int	ft_type(char *format, va_list list, t_buff *buff_size)
{
	t_struct	*inform;

	inform = ft_memalloc(sizeof(t_struct));
	inform->fuckup = 0;
	while (format[inform->fuckup++])
	{
		if (ft_diouxx(inform, format[inform->fuckup]))
		{
			ft_flag(inform, (char *)format, buff_size, list);
			if (!(format[inform->fuckup + 1] == '\0'))
			{
				buff_size->test = 1;
				return (inform->fuckup);
			}
			if (format[inform->fuckup + 1] == '\0')
				return (inform->fuckup);
			break ;
		}
	}
	free(inform);
	return (0);
}
