/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:03:43 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/07 20:00:51 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(int ac, char **av) 
{
    int a = -1122;
    int b = -144;
    int c = -1455;
    int d = -130;
	printf("tut %+10dsalam %+10d%d gogo%-i", b, a, c, d);
    ft_printf("tut %+10dsalam %+10d%d gogo%-i", b, a, c, d);
    return (0);
}