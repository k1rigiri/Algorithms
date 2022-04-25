#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int x, y;
} Point, *pPoint;

double d(Point *A, Point *B);

int main()
{
    Point A={0,-3}, B={0,1};
    pPoint pA = &A, pB = &B;
    printf("d=%f", d(pA, pB));
}

double d(Point *A, Point *B)
{
    //return sqrt(pow(((*A).x - (*B).x),2)+pow(((*A).y - (*B).y),2))
    return sqrt(pow(A->x - B->x,2)+pow(A->y - B->y,2));
}
