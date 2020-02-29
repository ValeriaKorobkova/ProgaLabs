#include <stdio.h>
#include "array_utils.c"

void print_positive();
void reqursive_print(int array[], int n, int i);
long long from_dec_to_bin(int dec, int i);

int main(int argc, char const *argv[])
{
    print_positive();
    printf("\n");
    printf("=========================\n");
    //=========================
    int n;
    scanf("%d", &n);
    int array[n];
    fill_rnd(array, n);
    print_array(array, n);
    reqursive_print(array, n, 0);
    printf("\n");
    printf("=========================\n");
    //==========================
    int dec;
    scanf("%d", &dec);
    printf("%lld\n", from_dec_to_bin(dec, 0));
    return 0;
}

void print_positive()
{
    int x;
    scanf("%d", &x);
    if (x != 0)
    {
        print_positive();
        if (x > 0)
            printf("%d ", x);
    }
}

void reqursive_print(int array[], int n, int i)
{
    if (i < n)
    {
        if (array[i] > 0)
            printf("%d ", array[i]);
        reqursive_print(array, n, i + 1);
        if (array[i] < 0)
            printf("%d ", array[i]);
    }
}

long long power(int base, int exp)
{
    long long result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

long long from_dec_to_bin(int dec, int i)
{
    if (dec <= 1)
        return dec * power(10, i);

    int mod = dec % 2;
    return mod * power(10, i) + from_dec_to_bin(dec / 2, i + 1);
}