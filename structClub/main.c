#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct
{
    char name[10];
    int liga;
    int result;
} club;

void BaskEnter(club *a);
void BaskPrint(club *a, int lig);
void SortClub(club *a);

int main()
{
    int nl;
    club bask[N];
    BaskEnter(bask);
    SortClub(bask);
    printf("Enter needed lig:");
    scanf("%d", &nl);
    BaskPrint(bask, nl);
}

void BaskEnter(club *a)
{
    for (int i = 0; i < N; i++)
    {
        printf("Enter name:\n");
        scanf("%s", &a[i].name);
        printf("Enter liga:\n");
        scanf("%d", &a[i].liga);
        printf("Enter result:\n");
        scanf("%d", &a[i].result);
        printf("----------------------\n");
    }
}

void BaskPrint(club *a, int nl)
{

    printf("Clubs:\n");
        for (int i = 0; i < N; i++)
        {
            if (nl == a[i].liga)
            {
                printf("Name =  %s\n", a[i].name);
                printf("Liga = %d\n", a[i].liga);
                printf("Result = %d\n", a[i].result);
                printf("----------------------\n");
            }
        }
    }

void SortClub(club *a)
{
    club temp;
    int x;
    for (int i = 1; i < N; i++)
    {
        x = i - 1;
        temp = a[i];
        while(x >= 0 && a[x].result > temp.result)
        {
            a[x+1] = a[x];
            a[x] = temp;
            x--;
        }
    }
}
