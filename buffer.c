/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:58:10 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/07 19:55:49 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void add_to_list(char *str, t_buff *buff_size, size_t len)
{
    int i;
    int struct_len;

    struct_len = sizeof(buff_size->p_begin->value);
    i = 0;   
    if (buff_size->flag)
    {
        buff_size->p_begin = ft_create_list(1);
        buff_size->flag = 0;
        ft_bzero(buff_size->p_begin->value, struct_len); 
    }
    ft_strcat(buff_size->p_begin->value, str);
}