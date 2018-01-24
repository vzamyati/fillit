#include "fillit.h"
#include <stdio.h>

void	print_list(t_tetri *list)
{
    t_tetri *elem;
    int     j;

    elem = list;
    while(elem->next)
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