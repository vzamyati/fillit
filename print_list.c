#include "fillit.h"

void	print_list(t_tetri *list)
{
    t_tetri *elem;
    int     j;

    elem = list;
	printf("Forward\n");
    while (elem)
    {
        j = 0;
        while (j < 4)
        {
            printf("%c: x[%d]=%d y[%d]=%d\n", elem->c, j, elem->x[j], j, elem->y[j]);
            j++;
        }
        elem = elem->next;
    }
}

void    print_rev_list(t_tetri *list)
{
	t_tetri *elem;
	int j;

	elem = list;
	printf("Reverse\n");
	while (elem->next)
		elem = elem->next;
	elem = elem->prev;
	while (elem)
	{
		j = 0;
		while (j < 4)
		{
			printf("%c: x[%d]=%d y[%d]=%d\n", elem->c, j, elem->x[j], j, elem->y[j]);
			j++;
		}
		elem = elem->prev;
	}
}

void    print_map(char **map)
{
	int j;

	j = 0;
	while (map[j])
	{
		printf("%s\n", map[j]);
		j++;
	}
}