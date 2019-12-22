/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:03:43 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/22 20:07:01 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(void) 
{
    // int a = -42;
    // int b = -144;
    // int c = 1455;
    // int d = -130;
    printf("\nreturn %d\n", ft_printf("%5.2s is a string", "this"));
    printf("\nreturn %d\n", printf("%2.2s is a string", "this"));
    return (0);
}