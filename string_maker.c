/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:12:19 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/22 19:31:42 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void width_and_precision(t_struct *inform, size_t len)
{
	if (inform->width > inform->precision)
		inform->final_size = inform->width;
	else
	{
		inform->final_size = inform->precision;
		if ((inform->type == 'X' || inform->type == 'x') && inform->sharp && inform->value_d != 0)
			inform->final_size += 2;
			
	}
	if (inform->final_size < len)
		inform->final_size = len;
}

int flag_corrector(t_struct *inform)
{
	if (inform->ll == 1)
	{
		inform->l = 0;
		inform->h = 0;
		inform->h = 0;
		return (1);
	}
	if (inform->l == 1)
	{
		inform->h = 0;
		inform->hh = 0;
		return (2);
	}
	if (inform->h == 1)
	{
		inform->hh = 0;
		return (3);
	}
	if (inform->hh == 1)
		return (4);
	return (5);
}

int va_value(t_struct *inform, va_list list, int i)
{
    int len;

    len = 0;
	if (inform->type == 'd')
		len = ft_value_d(inform, list, i);
	else if (inform->type == 'u')
		len = ft_value_u(inform, list, i);
	else if (inform->type == 'o')
		len = ft_value_o(inform, list, i);
	else if (inform->type == 'x' || inform->type == 'X')
		len = ft_value_x(inform, list, i);
	else if (inform->type == 'c' || inform->type == '%')
		len = ft_value_c(inform, list, i);
	else if (inform->type == 's')
		len = ft_value_s(inform, list, i);
    return (len);
}

int ft_value_maker(t_struct *inform, t_buff *buff_size, va_list list)
{
    size_t len;
	int i;

    len = 0;
	i = flag_corrector(inform);
	len = va_value(inform, list, i);
	width_and_precision(inform, len);
	ft_make_arg(inform, buff_size, len);
	buff_size->size_of_all += inform->final_size; // dupl
    free(inform);
    return (0);
}



	// printf("              FLAGS\n");
    // printf("MINUS %d\n", inform->minus);
    // printf("PLUS %d\n", inform->plus);
    // printf("SPACE %d\n", inform->space);
    // printf("ZERO %d\n", inform->zero);
    // printf("SHARP %d\n", inform->sharp);
	// printf("WIDTHMINUS %d\n", inform->widthisneg);
    // printf("              TOCHNOST\n");
    // printf("%d\n", inform->precision);
    // printf("              WIDTH\n");
    // printf("%d\n", inform->width);
    // printf("              MODIF\n");
    // printf("h %d\n", inform->h);
    // printf("hh %d\n", inform->hh);
    // printf("l %d\n", inform->l);
    // printf("ll %d\n", inform->ll);