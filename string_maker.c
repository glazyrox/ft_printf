/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:12:19 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/27 20:44:37 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_maker(t_struct *inform, t_buff *buff_size)
{
    printf("\n%d", buff_size->buff_size);
    char *str;
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
    free(inform);
    return (0);
}