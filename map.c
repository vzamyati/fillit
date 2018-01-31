/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:13:36 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/31 15:13:37 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			size_map(int nmb)
{
	int		n;

	n = 2;
	while (1)
	{
		if (nmb * 4 <= n * n)
			return (n);
		n++;
	}
}

char		**gen_map(int n)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (n + 1))))
		ft_error();
	while (j < n)
	{
		i = 0;
		if (!(map[j] = (char*)malloc(sizeof(char) * n + 1)))
			ft_error();
		while (i < n)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}

char		**write_tetri(t_tetri *list, char **map, int n)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (j < n)
	{
		i = 0;
		while (i < n)
		{
			if (list->x[count] == i && list->y[count] == j)
			{
				map[j][i] = list->c;
				count++;
			}
			i++;
		}
		j++;
	}
	map[j] = NULL;
	return (map);
}

char		**clear_tetri(t_tetri *list, char **map, int n)
{
	int		i;
	int		j;

	j = 0;
	while (j < n)
	{
		i = 0;
		while (i < n)
		{
			if (map[j][i] == list->c)
				map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}
