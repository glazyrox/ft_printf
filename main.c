/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:03:43 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/23 19:51:16 by rgwayne-         ###   ########.fr       */
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
    printf("\nreturn %d\n", ft_printf("%2.9p", 1234));
    printf("\nreturn %d\n", printf("%2.9p", 1234));
    return (0);
}