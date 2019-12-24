/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:03:43 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/24 18:01:25 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(void) 
{
    // int a = -42;
    // int b = -144;
    // int c = 1455;
    char d = {"HELLO"};
    printf("\nreturn %d\n", ft_printf("%.0p", 0));
    printf("\nreturn %d\n", printf("%.0p", 0));
    return (0);
}