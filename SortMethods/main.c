#include <stdio.h>
#include <stdlib.h>

const int size = 50;

void rand_arr(int* M);
void print_arr(int* M);
void copy_arr(int* A,int* M);
void bubble(int* M);
void new_bubble(int* M);
void shaker(int* M);
void selectionsort(int* M);
void insertsort(int* M);
void shella(int* M);

int  main()
{
    int A[size], B[size];
    rand_arr(A);
    copy_arr(A,B);
//    bubble(B);
//    new_bubble(B);
//    shaker(B);
//    selectionsort(B);
//    insertsort(B);
    shella(B);
    print_arr(B);
}

void rand_arr(int* M)
{
    srand(time(NULL));
    for (int i= 0; i < size; i++)
        M[i] = rand()%51;
}

void print_arr(int* M)
{
    for(int i = 0; i < size; i++)
        printf("%d\t", M[i]);
}

void copy_arr(int* A, int* M)
{
    for (int i = 0; i < size; i++)
        M[i] = A[i];
}

void bubble(int* M)
{
    int i, j, buf;
    for (i = 0; i < size-1; i++)
    {
        for (j = size - 1; j > i; j--)
        {
            if (M[j-1] > M[j])
            {
                buf = M[j];
                M[j] = M[j-1];
                M[j-1] = buf;
            }
        }
    }
}

void new_bubble(int* M)
{
    int i, j = 0, buf, n;
    do
    {
        n = j;
        for (i = size - 1; i > n; i--)
        {
            if (M[i-1] > M[i])
            {
                j = i;
                buf = M[i];
                M[i] = M[i-1];
                M[i-1] = buf;
            }
        }
    }while(j-n);
}

void shaker(int* M)
{
    int i, j, buf, start = 0, end = size - 1;
    do
    {
        for (i = end; i > start; i--)
        {
            if(M[i-1] > M[i])
            {
                j = i;
                buf = M[i];
                M[i] = M[i-1];
                M[i-1] = buf;
            }
        }
        start = j;
        for (i = start; i <= end; i++)
        {
            if(M[i-1] > M[i])
            {
                buf = M[i];
                M[i] = M[i-1];
                M[i-1] = buf;
                j = i;
            }
        }
        end = j - 1;
    }while(start < end);
}

void selectionsort(int* M)
{
    int i, j, buf, im;
    for (i = 0; i < size - 1; i++)
    {
        im = i;
        for (j = i + 1; j < size; j++)
        {
            if (M[j] < M[im])
                im = j;
        }
        if (i != im)
        {
            buf = M[i];
            M[i] = M[im];
            M[im] = buf;
        }
    }
}

void insertsort(int* M)
{
    int i, j, buf;
    for (i = 0; i < size; i++)
    {
        if (M[i] < M[i-1])
        {
            buf = M[i];
            for (j = i-1; j >= 0 && M[j] > buf; j--)
            {
                M[j+1] = M[j];
            }
            M[j+1] = buf;
        }
    }
}

void shella(int* M)
{
    int i, j, step, buf;
    step = size;
    step /= 2;
    while(step > 0)
    {
        for (i = 0; i < size - step; i++)
        {
            j = i;
            while(j >= 0 && M[j] > M[j+step])
            {
                buf = M[j];
                M[j] = M[j+step];
                M[j+step] = buf;
                j--;
            }
        }
        step /= 2;
    }
}
