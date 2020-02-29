#include <stdio.h>

double absolute(double x);
double cosine(float x);
double power(float x, int n);
long long fact(int x);

int main(int argc, char const *argv[])
{
    float x;
    scanf("%f", &x);
    printf("power = %f\n", power(x, -2));
    printf("fact = %lld\n", fact(x));
    printf("cos = %f\n", cosine(x));
    return 0;
}

double power(float x, int n)
{
    double p = 1;
    for (int i = 0; i < absolute(n); i++)
    {
        p *= x;
    }
    if (n < 0)
    {
        p = 1 / p;
    }
    return p;
}

long long fact(int x)
{
    long long f = 1;
    if (x < 0)
    {
        return -1;
    }

    for (int i = 2; i <= x; i++)
    {
        f *= i;
    }

    return f;
}

double absolute(double x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

double cosine(float x)
{
    double sum = 0;
    double term = 1;
    for (int i = 0; absolute(term) > 0.0001; i += 2)
    {
        term = power(x, i) / fact(i) * power(-1, i / 2);
        sum += term;
    }

    return sum;
}