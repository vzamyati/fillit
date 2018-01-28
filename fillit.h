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

typedef struct 		s_tetri
{
	int				x[4];
	int				y[4];
	char			c;
	struct s_tetri	*next;
    struct s_tetri  *prev;
}					t_tetri;

int					ft_valid(char *buf); // первая проверка фигуры
void				ft_error(void); // выводит error при невалидной карте
char				*ft_read_file(char *av); // считывание файла
t_tetri 			*parse_tetri(char *buf); //запись фигур в список
int                 count_blocks(char *buf);
void				ft_bzero(void *s, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char                **gen_map(int n);
int                 size_map(int nmb);
int     			check_insert_tetri(t_tetri *list, char **map, int n);
char    			**write_map(t_tetri *list, char **map, int n);
char    			**clear_map(t_tetri *list, char **map, int n);
void    			solve_map(t_tetri *list, int nmb);

void				print_list(t_tetri *list); // для проверки
void                print_map(char **map); //checking...

#endif
