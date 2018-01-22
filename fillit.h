/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:49:48 by eaptekar          #+#    #+#             */
/*   Updated: 2018/01/22 12:48:32 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

#include <stdio.h>

typedef struct s_tetri
{
    int             x[4];
    int             y[4];
    char            c;
    struct s_tetri  *next;
}               t_tetri;

int		ft_valid(char *av); // первая проверка фигуры
void    ft_error(void); // выводит error при невалидной карте
char    *ft_read_file(char *av); // считывание файла
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);

#endif
