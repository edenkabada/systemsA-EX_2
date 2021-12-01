#include "my_mat.h"
#include <stdio.h>
#include <limits.h>
#define INFINITY UINT_MAX / 2 - 1

void fill_mat()
{
    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            scanf("%d", &graph_mat[i][j]);
        }
    }
    printf("\n\n");
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
                printf("%d ", dist[i][j]);
            }
            else if (graph_mat[i][j])
            {
                dist[i][j] = graph_mat[i][j];
                printf("%d ", dist[i][j]);
            }
            else
            {
                dist[i][j] = INFINITY;
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
    for (int k = 0; k < MAT_SIZE; k++)
    {
        for (int i = 0; i < MAT_SIZE; i++)
        {
            for (int j = 0; j < MAT_SIZE; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("\n");
for (int i = 0; i < MAT_SIZE; ++i){
for (int j = 0; j < MAT_SIZE; ++j){
    printf("%d ", dist[i][j]);
}
printf("\n");
}
}

void path_exists(int i, int j)
{
    if (dist[i][j] != INFINITY)
    {
        printf("True\n");
    }
    else
        printf("False\n");
}

void shortest_path(int i, int j)
{
    if (dist[i][j] != INFINITY)
    {
        printf("%d ", dist[i][j]);
    }
    else
        printf("-1");
}
