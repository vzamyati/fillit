//
// Created by Eugene APTEKAR on 1/24/18.
//

#include "fillit.h"

static void     new_coord(t_tetri **list, int i, int j)
{
    int count;

    count = 3;
    while (count >= 0)
    {
        (*list)->x[count] += i - (*list)->x[0];
        (*list)->y[count] += j - (*list)->y[0];
        count--;
    }
}

static char     **rec_alg(char **map, t_tetri *list, int n)
{
    int     i;
    int     j;
    char    **final_map;

    j = 0;
    if (list->next == NULL)
        return (map);
    final_map = NULL;
	while (j < n)
    {
        i = 0;
        while (i < n) {
	        new_coord(&list, i, j);
	        if (!check_insert_tetri(list, map, n))
	        {
		        final_map = rec_alg(write_tetri(list, map, n), list->next, n);
		        if (final_map)
			        return (final_map);
	            map = clear_tetri(list, map, n);
            }
            i++;
        }
        j++;
    }
    return (NULL);
}

/*static char     **fill_map(char **map, t_tetri *list, int n)
{
	int     i;
	int     j;

	j = 0;
	while (j < n)
    {
	    i = 0;
	    while (i < n)
	    {
		    new_coord(&list, i, j);
		    if (!check_insert_tetri(list, map, n))
		    {
			    map = write_tetri(list, map, n);
			    list = list->next;
			    if (!list)
				    return (map);
		    }
		    i++;
	    }
	    j++;
    }
	return (NULL);
}

static char     **backtrack(char **map, t_tetri *list, int n)
{
	char **final_map;
}
	final_map = fill_map(map, list, n);
	if (!final_map)
	{
		map = clear_tetri(list, map, n);
		list = list->prev;

}*/

void            solve_map(t_tetri *list, int nmb)
{
    int     n;
    char    **map;
    char    **result;

    n = size_map(nmb);
    map = gen_map(n);
    while (!(result = rec_alg(map, list, n)))
    {
        n++;
        free(map);
        map = gen_map(n);
    }
    print_map(result);
}
