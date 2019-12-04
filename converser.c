/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:02:37 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/04 20:47:06 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *ft_spacer(char *s1, char sym, t_struct *inform, int flag, int len)
{
	size_t i;
	size_t g;

	i = 0;
	g = 0;
	if (flag == 1)
	{
		while (s1[i])
			i++;
		s1[inform->final_size] = '\0';
		while (i < inform->final_size)
			s1[i++] = sym;
	}
	else
	{
	}
	return (s1);
}

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