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
    int **matrix_ = new_int_array(m - 1);
    int max_i = 0;
    int max_j = 0;
    rng(0, 50);
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new_int_array(n);
        matrix_[i] = new_int_array(n - 1);
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

    int i_ = 0;
    for (int i = 0; i < m; i++)
    {
        if (i == max_i)
            continue;
        int j_ = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == max_j)
                continue;
            matrix_[i_][j_] = matrix[i][j];
            j_++;
        }
        i_++;
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            printf("%4d ", matrix_[i][j]);
        }
        printf("\n");
    }
}

void task_2()
{
    int m, n;
    printf("Enter m, n: ");
    scanf("%d %d", &m, &n);

    int **matrix_ = new_int_array(m);
    int **matrix = new_int_array(m + 1);

    rng(0, 50);
    for (int i = 0; i <= m; i++)
    {
        matrix_[i] = new_int_array(n);
        matrix[i] = new_int_array(n + 1);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix_[i][j] = rng(0, 50);
            matrix[i][j] = matrix_[i][j];
            matrix[i][n] += matrix[i][j];
            matrix[m][j] += matrix[i][j];
            matrix[m][n] += matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", matrix_[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%4d ", matrix[i][j]);
        }

        printf("\n");
    }
}
