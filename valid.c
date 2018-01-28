/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:06:49 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/22 13:14:01 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int     ft_valid_conn(char *buf, int j)
{
    int     touch;
    int     i;

    i = 0;
    touch = 0;
    while (buf[i + j] && i < 20)
    {
        if (buf[i + j] == '#')
        {
            if (buf[i + j] == buf[i + j + 1]) // чек справа
                touch++;
            if (i > 0 && (buf[i + j] == buf[i + j - 1])) // чек слева (если не на нулевой позиции)
                touch++;
            if (i < 15 && (buf[i + j] == buf[i + j + 5])) // чек вниз (если не в последнем ряду)
                touch++;
            if (i > 4 && (buf[i + j] == buf[i + j - 5])) // чек вверх (если не в первом ряду)
                touch++;
        }
        i++;
    }
    if (touch == 6 || touch == 8)
        return (0);
    return (1);
}

static int     ft_valid_symbol(char *buf, int j)
{
    int dot;
    int hash;
    int endl;
    int i;

    i = 0;
    dot = 0;
    hash = 0;
    endl = 0;
    while (buf[i + j] && i < 20)
    {
        if (buf[i + j] != '.' && buf[i + j] != '#' && buf[i + j] != '\n')
            ft_error();
        else if (buf[i] == '.')
            dot++;
        else if (buf[i] == '#')
            hash++;
        else if (buf[i] == '\n')
            endl++;
        i++;
    }
    if (dot == 12 && hash == 4 && endl == 4)
        return (0);
    return (1);
}

int     ft_valid(char *buf)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (buf[i + j])
    {
        if (ft_valid_conn(buf, j) || ft_valid_symbol(buf, j))
            return (1);
        if (buf[4 + j] == '\n' && buf[9 + j] == '\n' && buf[14 + j] == '\n'
            && buf[19 + j] == '\n' && buf[20 + j] == '\0')
            return (0);
        if (buf[4 + j] == '\n' && buf[9 + j] == '\n' && buf[14 + j] == '\n'
            && buf[19 + j] == '\n' && buf[20 + j] == '\n' && (buf[21 + j] == '.' || buf[21 + j] == '#'))
            j += 21;
        else
            return (1);
    }
    return (0);
}

int     check_insert_tetri(t_tetri *list, char **map, int n)
{
    int count;

    count = 0;
    while (count < 4)
    {
        if (list->x[count] < n && list->y[count] < n &&
                map[list->y[count]][list->x[count]] == '.')
        {
            if (count == 3)
                return (0);
        }
        count++;
    }
    return (1);
}
