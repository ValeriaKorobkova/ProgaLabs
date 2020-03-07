#include <stdio.h>
#include <stdlib.h>
#include "array_utils.c"

#define new_int_array(n) malloc(sizeof(int) * n)
#define new_float_array(n) malloc(sizeof(float) * n)

void task_1();
void task_2();
void task_3();
void insertion_sort(float *array[], int size);

int main(int argc, char const *argv[])
{
    task_1();
    printf("=================================\n");
    task_2();
    printf("=================================\n");
    task_3();
    return 0;
}

void task_1()
{
    int *b;
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    b = malloc(sizeof(int) * n);

    if (!b)
    {
        printf("Allocation error!\n");
        exit(1);
    }

    fill_rnd(b, n);
    print_array(b, n);

    int m = 0;
    int o = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= 0)
            m++;
        else
            o++;
    }

    int *c = malloc(sizeof(int) * m);
    int *d = malloc(sizeof(int) * o);

    int j = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= 0)
            c[j++] = b[i];
        else
            d[k++] = b[i];
    }

    print_array(c, m);
    print_array(d, o);
}

void task_2()
{
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    float *a = new_float_array(n);
    float **b = new_int_array(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = (float)((rand() / (double)RAND_MAX) * (50 - (-50)) - 50);
        b[i] = &a[i];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%.3f:", a[i]);
        printf("%lX  ", (long int)b[i]);
    }

    insertion_sort(b, n);

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%f:", *b[i]);
        printf("%lX  ", (long int)b[i]);
    }

    printf("\n");
}

void task_3()
{
    int n;
    printf("Enter max number: ");
    scanf("%d", &n);

    int *numbers = calloc(sizeof(int), n);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && i != 2)
        {
            numbers[i] = 1;
        }
        if (i % 3 == 0 && i != 3)
        {
            numbers[i] = 1;
        }
        if (i % 5 == 0 && i != 5)
        {
            numbers[i] = 1;
        }
        if (i % 7 == 0 && i != 7)
        {
            numbers[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!numbers[i])
            printf("%d ", i);
    }
    printf("\n");
}

void insertion_sort(float *array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        float *t = array[i];
        int j = i - 1;

        while (j >= 0 && *t < *array[j])
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = t;
    }
}