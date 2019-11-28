/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:12:19 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/28 21:30:02 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"



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

void flag_corrector(t_struct *inform)
{
	if (inform->ll == 1)
	{
		inform->l = 0;
		inform->h = 0;
		inform->h = 0;
	}
	if (inform->l == 1)
	{
		inform->h = 0;
		inform->hh = 0;
	}
	if (inform->h == 1)
		inform->hh = 0;
}

int ft_value_maker(t_struct *inform, t_buff *buff_size) //ренейм
{
    char *str;
    int len;

    len = 0;
	flag_corrector(inform);
    len = int_len((short)inform->value_d, inform);
    free(inform);
    return (0);
}



// printf("              FLAGS\n");
    // printf("MINUS %d\n", inform->minus);
    // printf("PLUS %d\n", inform->plus);
    // printf("SPACE %d\n", inform->space);
    // printf("ZERO %d\n", inform->zero);
    // printf("SHARP %d\n", inform->sharp);
    // printf("              TOCHNOST\n");
    // printf("%d\n", inform->precision);
    // printf("              WIDTH\n");
    // printf("%d\n", inform->width);
    // printf("              MODIF\n");
    // printf("h %d\n", inform->h);
    // printf("hh %d\n", inform->hh);
    // printf("l %d\n", inform->l);
    // printf("ll %d\n", inform->ll);