/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:03:43 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/19 21:10:17 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(int ac, char **av) 
{
    int a = -42;
    int b = -144;
    int c = 1455;
    int d = -130;
    printf("\nreturn %d\n", ft_printf("%x", 4294967296));
    printf("\nreturn %d\n", printf("%x", 4294967296));
    return (0);
}