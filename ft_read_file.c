/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 08:57:54 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/22 18:46:42 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_read_file(char *av)
{
	int		fd;
	char	*buf;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error();
	if (!(buf = ft_strnew(546)))
		ft_error();
	read(fd, buf, 546);
	if (ft_valid(buf) == 1)
		ft_error();
	close(fd);
	return (buf);
}
