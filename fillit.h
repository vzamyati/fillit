/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:49:48 by eaptekar          #+#    #+#             */
/*   Updated: 2018/01/12 18:54:47 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

#include <fcntl.h>

int		ft_valid_general(char *str); // первая проверка фигуры
void    ft_error(void); // выводит error при невалидной карте
int     ft_valid_connections(char *buf, int i); // количество косаний у # в этой позиции
int     ft_valid_tetra(char *buf); // чекает валидность тетрамины по касаниям
char    *ft_read_file(char *av); // считывание файла

#endif
