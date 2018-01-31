/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:11:30 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/31 15:11:32 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(const char *s)
{
	while (s && *s)
		ft_putchar(*s++);
	ft_putchar('\n');
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			((unsigned char*)s)[i] = '\0';
			i++;
		}
	}
}

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero((void*)str, size + 1);
	return (str);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = (char*)malloc(sizeof(char) * len + 1);
	if (sub && s)
	{
		while (len--)
		{
			sub[i] = s[start++];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
