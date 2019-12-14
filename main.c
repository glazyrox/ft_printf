/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:03:43 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/14 20:23:33 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(int ac, char **av) 
{
    long long test = -42;
    int a = 112;
    int b = -144;
    int c = 1455;
    int d = -130;
    printf("\nreturn %d\n", ft_printf("% 10.5d", 4242));
    printf("\nreturn %d\n", printf("% 10.5d", 4242));
    return (0);
}