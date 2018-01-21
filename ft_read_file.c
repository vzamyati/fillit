/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 08:57:54 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/16 08:57:55 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

 char    **getting_map(char *str)
 {
     int i;



 }

char    *ft_read_file(char *av)
{
    int fd;
    char *buf;

    fd = open(av, O_RDONLY);
    if (!(buf = ft_strnew(546)))
        return (0);
    read(fd, buf, 546);
    close (fd);
    return (buf);
}
