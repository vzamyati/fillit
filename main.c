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

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_putstr(ft_read_file(av[1]));
	else
		ft_putstr("usage: ./fillit map_file\n");
	return (0);
}
