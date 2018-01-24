/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 08:57:54 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/22 13:27:24 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//need to free buf

char        *ft_read_file(char *av)
{
    int     fd;
    char    *buf;

    fd = open(av, O_RDONLY);
    if (fd == -1)
        ft_error();
    if (!(buf = ft_strnew(546)))
        ft_error();
    read(fd, buf, 546);
    if (ft_valid(buf) == 1)
        ft_error();
    close (fd);
    return (buf);
}

int count_blocks(char *buf) {
	int nmb;
	int i;

	nmb = 1;
	i = 20;
	while (buf[i] && buf[i] == '\n')
	{
		nmb++;
		i += 21;
	}
	return (nmb);
}

static void    tetri_coord(t_tetri **tmp, char *buf, int nmb)
{
    int     i;
    int     j;
    int     all;
    char    *array;

    i = 0;
    j = 0;
    all = count_blocks(buf);
    array = ft_strsub(buf, (unsigned int)(all - nmb) * 21, 20);
    while (i < 20)
    {
        if (array[i] == '#')  //записываем координаты тетрамины (x, y)
        {
            (*tmp)->x[j] = i % 5;
            (*tmp)->y[j] = i / 5;
            j++;
        }
        i++;
    }
    free(array);
}

static void     mod_coord(t_tetri **tmp)
{
	int     min_x;
	int     min_y;
	int     j;

	j = 1;
	min_x = (*tmp)->x[0];
	min_y = (*tmp)->y[0];
	while (j < 4)
	{
		if ((*tmp)->x[j] < min_x)
			min_x = (*tmp)->x[j];
		j++;
	}
	j = 1;
	while (j < 4)
	{
		if ((*tmp)->y[j] < min_y)
			min_y = (*tmp)->y[j];
		j++;
	}
	while (--j >= 0) //нормировка координат
	{
		(*tmp)->x[j] = (*tmp)->x[j] - min_x;
		(*tmp)->y[j] = (*tmp)->y[j] - min_y;
	}
}

t_tetri     *parse_tetri(char *buf)
{
    char    c;
    int     nmb;
    t_tetri *tmp;
    t_tetri *list;

    nmb = count_blocks(buf);
    c = 'A';
    if (!(list = (t_tetri*)malloc(sizeof(t_tetri))))
        ft_error();
    tmp = list;
    while (nmb > 0)
    {
        tmp->c = c;
        tetri_coord(&tmp, buf, nmb);
	    mod_coord(&tmp);
        if (!(tmp->next = (t_tetri*)malloc(sizeof(t_tetri))))
            ft_error();
        tmp = tmp->next;
        c++;
        nmb--;
    }
    tmp = NULL;
    return (list);
}