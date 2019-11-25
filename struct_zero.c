/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:51:29 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/25 20:09:22 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void struct_zero(t_struct *inform)
{
    inform->minus = 0;
    inform->plus = 0;
    inform->size = 0;
    inform->space = 0;
    inform->sharp = 0;
    inform->zero = 0;
    inform->type = '\0';
    inform->value = NULL;
    inform->width = 0;
    inform->precision = 0;
}