/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzamyati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:06:49 by vzamyati          #+#    #+#             */
/*   Updated: 2018/01/12 19:06:54 by vzamyati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * проверка на касания # с соседними хешами на карте
 */

int     ft_valid_connections(char *buf, int i)
{
    int     touch;

    touch = 0;
    if (buf[i] == buf[i + 1]) // чек справа
        touch++;
    if (i != 0)
        if (buf[i] == buf[i - 1]) // чек слева (если не на нулевой позиции)
            touch++;
    if (i < 15) // чек вниз (если не в последнем ряду)
        if (buf[i] == buf[i + 5])
            touch++;
    if (i < 4) // чек вверх (если не в первом ряду)
        if (buf[i] == buf[i - 5])
            touch++;
    return (touch);
}

/*
 * дальше делаем проверку на валидность самой тетраминки: суммарно каждая фигура
 * должна содержать в себе 4 #, каждый минимум 1 раз должен соприкасаться с еще
 * одним #, + каждая фигура должна содержать в себе минимум одно двойное касание
 */

int     ft_valid_tetra(char *buf)
{
    int i;
    int one_connect;
    int double_connect;

    i = 0;
    one_connect = 0;
    double_connect = 0;
    while(buf[i]) {
        if (buf[i] == '#') {
            if (ft_valid_connections(buf, i) >= 1) // у # одно касание с другим #
                one_connect++;
            if (ft_valid_connections(buf, i) == 2) // у # два касания с другим #
                double_connect++;
            if (ft_valid_connections(buf, i) == 3) // у # три касания, значит это квадрат
                return (1);
        }
        i++;
    }
    printf("one_connect =  %d\n", one_connect);
    printf("double_connect =  %d\n", double_connect);
    if (one_connect >= 2 && double_connect >= 1)
        return (1);
    return (0);
}

/*
 * самая первая проверка - чекаем на количество хешей, точек и переносов строки:
 * в одной правильной фигуре должно быть 4 хеша, 12 точек и 4(+1 разделяющий) \n
 * если фигура проходит - возвращаем true
 */

int     ft_valid_general(char *buf)
{
    int dot;
    int hash;
    int endl;
    int i;

    i = 0;
    dot = 0;
    hash = 0;
    endl = 0;
    while (buf[i] && i < 21)
    {
        if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
            ft_error();
        else if (buf[i] == '.')
            dot++;
        else if (buf[i] == '#')
            hash++;
        else if (buf[i] == '\n')
            endl++;
        i++;
    }
    printf("%d\n", dot);
    printf("%d\n", hash);
    printf("%d\n", endl);
    if (dot == 12 && hash == 4)
        if (ft_valid_tetra(buf)) {
            printf("valid!");
            return (1);
        }
    return 0;
}
