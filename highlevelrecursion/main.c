#include <stdio.h>
#include <stdlib.h>

int const n = 40;
float s = 0;
int size;

void fill_arr(float *X,int size);
void rand_arr(int *M);
void print_arr(int *M);
int min(int *M, int k);
int min1(int *M, int k, int min);
void sum(float *M, int l);
void print_sequence(int *M, int k);
int main()
{
    int M[n], k, l = 0;
    rand_arr(M);
    printf("Massive:\n");
//    fill_arr(M, 8);
    print_arr(M);
    printf("\nEnter k = ");
    scanf("%d", &k);
    printf("min = %d\n", min(M, k));
    printf("Enter sequence size = ");
    scanf("%d", &size);
    float mas[size];
    fill_arr(mas);
    sum(mas, l);
    printf("\nSum of mas = %f\n", s);
//    print_sequence(M,k);
}

void rand_arr(int *M)
{
    srand(time(NULL));
    for (int i= 0; i < n; i++)
        M[i] = rand()%51;
}

void fill_arr(float *X,int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%f", &X[i]);
    }
}

void print_arr(int *M)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", M[i]);
}

int min(int *M, int k)
{
    return min1(M, k, 99999);
}

int min1(int *M, int k, int min)
{
    if (k == n)
        return min;
    if (min > M[k])
        min = M[k];
    return min1(M, k+1, min);
}

//void sum()
//{
//    if (mas[0] > 0)
//    {
//        s += mas[0];
//        sum();
//    }
//    else
//        return;
//}

void sum(float *M, int l)
{
    if (M[l] > 0)
    {
        s += M[l];
        l++;
        return sum(M, l);
    }
    else
        return 0;
}

void print_sequence(int *M, int k)
{
    if (M[k] < 0)
    {
        printf("%d\t", M[k]);
        print_sequence(M, k+1);
    }
    else if (M[k] > 0)
    {
        print_sequence(M, k+1);
        printf("%d\t", M[k]);
    }
    else
        return printf("0");
}

//isdigit cony
