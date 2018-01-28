/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 09:07:19 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/22 13:20:02 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int ac, char **av)
{
    char    *buf;
	int     nmb;

	t_tetri *list;

    buf = ft_read_file(av[1]);
    if (ac == 2)
        printf("%s", buf);
    else
        write(1, "usage: ./fillit map_file\n", 25);
    nmb = count_blocks(buf);
	list = parse_tetri(buf);
	print_list(list);
    solve_map(list, nmb);
    free(buf);
    return (0);
}
