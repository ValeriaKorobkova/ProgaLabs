#include <stdio.h>
#include <stdlib.h>
#include "array_utils.c"

#define new_int_array(n) calloc(sizeof(long int), n)
#define new_float_array(n) calloc(sizeof(float), n)

void task_1();
void task_2();

int main(int argc, char const *argv[])
{
    task_1();
    printf("=================================\n");
    task_2();
    return 0;
}

void task_1()
{
    int m;
    printf("Enter m: ");
    scanf("%d", &m);
    int n = 5;

    int **matrix = new_int_array(m);
    int max_i = 0;
    int max_j = 0;
    rng(0, 50);
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new_int_array(n);
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = rng(0, 50);

            if (matrix[i][j] > matrix[max_i][max_j])
            {
                max_i = i;
                max_j = j;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < m; i++)
    {
        if (i == max_i)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (j == max_j)
                continue;
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void task_2()
{
}
