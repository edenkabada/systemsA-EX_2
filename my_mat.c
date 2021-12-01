
#include "my_mat.h"
#include <stdio.h>
#include "limits.h"
#define INFINITY UINT_MAX/2 - 1

void print_mat()
{
    printf("Graph mat\n");
    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            printf("%d ", graph_mat[i][j]);
        }
        printf("\n");
        printf("\n");
    }
    printf("dist mat\n");
    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}

void fill_mat()
{
    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            scanf("%d", &graph_mat[i][j]);
        }
    }
    floyd_warshall();
}

void floyd_warshall()
{

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (graph_mat[i][j])
            {
                dist[i][j] = graph_mat[i][j];
            }
            else
            {
                dist[i][j] = INFINITY;
            }
        }
    }

    for (int k = 0; k < MAT_SIZE; ++k)
    {
        for (int i = 0; i < MAT_SIZE; ++i)
        {
            for (int j = 0; j < MAT_SIZE; ++j)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void shortest_path(int i, int j)
{
    if (dist[i][j] != INFINITY)
    {
        printf("%d\n", dist[i][j]);
    }
    if(dist[i][j]==0){
         printf("%d\n", -1);
    }
    else
    {
        printf("%d\n", -1);
    }
}

void path_exists(int i, int j)
{
    if (dist[i][j] != INFINITY)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}
