/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:22:34 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/30 16:53:12 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void print_list(tNode *p_begin)
{
    tNode *p = p_begin;
    while (p != NULL) {
        //распечатать структуру данных
        printf("%s \t", p->value);
        //шагнуть вперед !!!
        p = p->next;
    }
}

tNode* ft_create_list(int N)
{
    int i;
    tNode *p_begin = NULL;
    tNode *p = NULL;

    i = 0;
    p_begin = (tNode *)malloc(sizeof(tNode));
    p = p_begin;
    p->next = NULL;

    while (i < N)
    {
        p->next = (tNode *)malloc(sizeof(tNode));
        //шагнуть вперед !!!
        p = p->next;
        //заполнить _новую_ структуру данных
        p->next = NULL;
        i++;
    }
    return (p_begin);
}