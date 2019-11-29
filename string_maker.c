/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:12:19 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/29 20:35:07 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void width_and_precision(t_struct *inform, int len)
{
	if (inform->width > inform->precision)
		inform->final_size = inform->width;
	else
		inform->final_size = inform->precision;
	if (inform->final_size < len)
		inform->final_size = len;
}

int int_len(int value, t_struct *inform)
{
    int i;
	
    i = 0;
    if (value < 0)
        i++;
    else 
    {
        if (inform->plus)
            i++;
    }
    while (value != 0)
    {
        value /= 10;
        i++;
    }
    return(i);
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
	return (0);
}

int ft_value_maker(t_struct *inform, t_buff *buff_size) //ренейм
{
    char *str;
    int len;
	int i;

    len = 0;
	i = flag_corrector(inform);
	if (i == 1)
		len = int_len((long long)inform->value_d, inform);
	else if (i == 2)
		len = int_len((long)inform->value_d, inform);
	else if (i == 3)
		len = int_len((short)inform->value_d, inform);
	else if (i == 4)
		len = int_len((char)inform->value_d, inform);
	width_and_precision(inform, len);
	buff_size->size_of_all += len;
	ft_make_buffer(inform, buff_size);
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