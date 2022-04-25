#include <stdio.h>
#include <stdlib.h>

double rec_fact_up(int x);
double rec_degree(double n, int x);
int NOD_iter(int x, int y);
int NOD_rec(int x, int y);
double Sum_elements(int* M, int x);
int fibonacci(int x);
void reverse();
double rec_step(float a, int b);

int main()
{
//    int x = 5;
//    float y = 5;
//    int i = 3;
//    int M[] = {1,2,3,4,5};
//    printf("rec_fact_up = %f\n", rec_fact_up(x));
//    printf("rec_degree = %f\n", rec_degree(y, i));
//    printf("sum_elements = %f\n", Sum_elements(M, 5));
//    printf("fibonacci = %d\n", fibonacci(x));
    Printchar(-491);
}

double rec_fact_up(int x)
{
    if (x <= 0)
        return 1.0;
    else
        return rec_fact_up(x-1) * x;
}

double rec_degree(double n, int x)
{
    double r;
    if (!x)
        return 1;
    if (!(x%2))
        return r = rec_degree(n, x/2), r*r;
    else
        return n*rec_degree(n, x-1);
}

double Sum_elements(int* M, int x)
{
    if (x == 1)
        return *M;
    else
        return Sum_elements(M, x - 1) + *(M+(x-1));
}

int fibonacci(int x)
{
    if (x == 1 || x == 0)
        return x;
    else
        return fibonacci(x-1) + fibonacci(x-2);
}

int NOD_iter(int m, int n)
{
    int r;
    do
    {
        r = m % n;
        m = n;
        n = r;
    }
    while(r);
    return m;
}

int NOD_rec(int m, int n)
{
    if (!(m % n))
    {
        return n;
    }
    else return NOD_rec(n, m % n);
}

void Printchar(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n)
    {
        Printchar(n/10);
        putchar(n%10 + '0');
    }
}

void reverse()
{
    int ch;
    if (( ch = getch() !='\r'))
    {
        reverse();
        putchar(ch);
    }
}

double rec_step(float a, int b)
{
    if (b <= 0)
        return 1.0;
    else
        return rec_step(a, b-1) * a;
}
