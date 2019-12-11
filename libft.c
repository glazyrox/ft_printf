/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgwayne- <rgwayne-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:04:09 by rgwayne-          #+#    #+#             */
/*   Updated: 2019/12/11 16:17:22 by rgwayne-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return ((unsigned char *)b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memalloc(size_t size)
{
	char *arr;

	if (size > 0)
	{
		arr = (void *)malloc(sizeof(unsigned char) * size);
		if (arr == 0)
			return (NULL);
		else
		{
			ft_bzero(arr, size);
			return (arr);
		}
	}
	else
		return (NULL);
}

char	*ft_strcat(char *s1, const char *s2, int dack)
{
	size_t i;
	size_t g;

	i = 0;
	g = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[g] != '\0')
	{
		if (s2[g] == 48 && dack == 1)
		{
			s1[i] = ' ';
			g++;
			i++;
		}
		s1[i] = s2[g];
		if (s2[g] == 48 && dack == 2)
		{
			s1[i] = ' ';
		}
		g++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}