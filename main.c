#include "my_mat.h"
#include <stdio.h>

int main()
{
    char c;
    printf("choose A-D\n");
    while ((scanf("%c", &c)) != 'D')
    {
        if (c == 'A')
        {
            fill_mat();
        }
        if (c == 'B')
        {
            int i, j;
            scanf("%d %d", &i, &j);
            path_exists(i, j);
        }
        if (c == 'C')
        {
            int i, j;
            scanf("%d %d", &i, &j);
            shortest_path(i, j);
        }
        if(c== 'D'){
            return 0;
        }
    }
}
