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

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_tetri
{
	int				x[4];
	int				y[4];
	char			c;
	struct s_tetri	*next;
}					t_tetri;

void				ft_putstr(const char *s);
char				*ft_read_file(char *av);
void				ft_error(void);
char				*ft_strnew(size_t size);
int					ft_valid(char *buf);
int					count_blocks(char *buf);
t_tetri				*parse_tetri(char *buf);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				solve_map(t_tetri *list, int nmb);
int					size_map(int nmb);
char				**gen_map(int n);
int					check_insert_tetri(t_tetri *list, char **map, int n);
char				**write_tetri(t_tetri *list, char **map, int n);
char				**clear_tetri(t_tetri *list, char **map, int n);
void				print_map(char **map);

#endif
