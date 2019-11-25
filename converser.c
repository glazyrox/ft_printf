/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:02:37 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/11/25 20:22:39 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_new_atoi(const char *str, int start, int end)
{
	int				i;
	long long int	nbr;

	i = start;
	nbr = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && i < end)
		nbr = 10 * nbr + (str[i++] - '0');
	return (nbr);
}