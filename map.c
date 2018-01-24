//
// Created by Eugene APTEKAR on 1/24/18.
//

#include "fillit.h"

int  size_map(int nmb)
{
	int n;

	n = 4;
	while (1)
	{
		if (nmb * 4 <= n * n)
			return (n);
		n++;
	}
}

char    **gen_map(int nmb)
{
	int     i;
	int     j;
	int     n;
	char    **map;

	j = 0;
	n = size_map(nmb);
	if (!(map = (char**)malloc(sizeof(char*) * n + 1)))
		ft_error();
	while (j < n)
	{
		i = 0;
		if(!(map[j] = (char*)malloc(sizeof(char) * n + 1)))
			ft_error();
		while (i < n)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	map[j] = NULL;
	return (map);
}
