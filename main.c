/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 09:07:19 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/30 14:30:43 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_error(void)
{
	ft_putstr("error");
	exit(1);
}

void		print_map(char **map)
{
	int		j;

	j = 0;
	while (map[j])
	{
		ft_putstr(map[j]);
		j++;
	}
}

int			main(int ac, char **av)
{
	char	*buf;
	int		nmb;
	t_tetri	*list;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit map_file");
		return (1);
	}
	buf = ft_read_file(av[1]);
	nmb = count_blocks(buf);
	list = parse_tetri(buf);
	solve_map(list, nmb);
	free(buf);
	free(list);
	return (0);
}
