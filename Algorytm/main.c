#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size = 50; //Отладка = 8; Рабочий режим size = 50
void Max_arr(int *M)
{
    srand(time(NULL));
    for (int i= 0; i<size; i++)
        M[i] = rand()%51;
}

void Print_arr(int *M)
{
    for (int i= 0; i<size; i++)
        printf("%d\t", M[i]);
}

void Copy_arr(int *A, int *B)
{
    for (int i = 0; i < size; i++)
        B[i] = A[i];
}

void Bubble(int *M)
{
    int i,j, buf, c = 0, p = 0;
    for (i = 0; i < size-1; i++)
    {
        for (j = size-1; j > i; j--)
        {
            c++;
            if (M[j-1] > M[j])
            {
                p++;
                buf = M[j];
                M[j] = M[j-1];
                M[j-1] = buf;
            }
        }
    }
    printf("\nBubble: compare%d, reshuffle=%d\n", c,p);
}

void Bubble_new(int *M)
{
    int i, j = 0, buf, m, c = 0, p = 0;
    do
    {
        m = j;
        for (i = size-1; i > m; i--)
        {
            c++;
            if (M[i-1] > M[i])
            {
                j = i;
                p++;
                buf = M[i];
                M[i] = M[i-1];
                M[i-1] = buf;
            }
        }
    } while (j - m);
    printf("\nModern_Bubble: compare=%d, reshuffle=%d\n", c, p);
}

void Shaker(int *M)
{
    int i,t, n1 = 0, n2 = size-1, j, c = 0, p = 0;
    do
    {
        for(i = n2; i > n1; i--)
        {
            c++;
            if (M[i-1] > M[i])
            {
                p++;
                j = i;
                t = M[i-1];
                M[i-1] = M[i];
                M[i] = t;
            }
        }
        n1 = j;
        for (i = n1; i <= n2; i++)
        {
            c++;
            if (M[i-1] > M[i])
            {
                t = M[i-1];
                M[i-1] = M[i];
                M[i] = t;
                j = i;
                p++;
            }
        }
        n2 = j - 1;
    } while (n1<n2);
    printf("\nShaker: compare=%d, reshuffle=%d\n", c, p);
}

void SelectionSort(int *M)
{
   int i, j, im, temp, c = 0, p = 0;
   for (i=0; i<size-1; i++)
   {
       im = i;
       for (j = i+1; j<size; j++)
       {
           c++;
           if (M[j]<M[im]) im = j;
       }
       c++;
       if (i!=im)
       {
           p++;
           temp = M[i];
           M[i] = M[im];
           M[im] = temp;
       }
   }
   printf("\nSelectionSort: compare = %d, reshuffle = %d\n", c, p);
}

void InsertSort(int *M)
{
    int i, j, temp, c = 0;
    double p = 0;
    for (i=1; i<size; i++)
    {
        if (M[i]<M[i-1])
        {
            c++;
            temp = M[i];
            p += 1./3;
            for (j = i-1; j>=0 && M[j] > temp; j--, c++)
            {
                p += 1./3;
                M[j+1] = M[j];
            }
            M[j+1] = temp;
            p += 1./3;
        }
    }
    printf("\nInsertSort: compare = %d, reshuffle = %lf\n", c, p);
}

void shella(int *M)
{
    int i, j, d, c = 0, p = 0, temp;
    d = size;
    d /= 2;
    while (d > 0)
    {
        for (i = 0; i<size-d; i++)
        {
            c++;
            j = i;
            while (j>= 0 && M[j]>M[j+d])
            {
                p++;
                temp = M[j];
                M[j] = M[j+d];
                M[j+d] = temp;
                j--;
            }
        }
        d /= 2;
    }
    printf("\nShella: compare = %d, reshuffle = %d\n", c, p);
}

void main()
{
    int A[size], B[size];
    Max_arr(A);
    Copy_arr(A,B);
    Bubble(B);
    Print_arr(B);
    Copy_arr(A,B);
    Bubble_new(B);
    Print_arr(B);
    Copy_arr(A,B);
    Shaker(B);
    Print_arr(B);
    Copy_arr(A,B);
    SelectionSort(B);
    Print_arr(B);
    Copy_arr(A,B);
    InsertSort(B);
    Print_arr(B);
    Copy_arr(A,B);
    shella(B);
    Print_arr(B);
    Copy_arr(A,B);
}

