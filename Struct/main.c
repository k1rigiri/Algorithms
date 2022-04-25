#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// struct тег{список переменных}элементы экземпл€ров;
struct Point
{
    int x, y;
} A, B;

struct Point1
{
    int x, y;
};

struct Point2
{
    int x, y;
} A2 = {0, -3}, B2 = {0,1};

typedef struct
{
    int x, y;
} Point3;

void main()
{
    double d;
    struct Point A = {0, -3}, B = {0,1};
    d = sqrt(pow((A.x - B.x),2)+pow((A.y - B.y),2));
    printf("%f", d);

}
