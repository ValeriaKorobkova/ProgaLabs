#include <stdio.h>
#include <stdlib.h>

int rng(int min, int max)
{
    return (int)((rand() / (double)RAND_MAX) * (max - min) + min);
}

void fill_inc(int array[], int size)
{
    array[0] = rng(0, 10);
    for (int i = 1; i < size; i++)
    {
        array[i] = rng(1, 10) + array[i - 1];
    }
}

void fill_dec(int array[], int size)
{
    array[0] = rng(42, 100);
    for (int i = 1; i < size; i++)
    {
        array[i] = array[i - 1] - rng(1, 10);
    }
}

void fill_rnd(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rng(-100, 100);
    }
}

int sum_array(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

int count_series(int array[], int size)
{
    int series = 1;
    for (int i = 1; i < size; i++)
    {
        if (array[i] <= array[i - 1])
        {
            series++;
        }
    }
    return series;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", array[i]);
    }

    printf("\n");
}