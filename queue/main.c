#include <stdio.h>
#include <stdlib.h>
#define N 11

typedef struct Node
{
    int val;    //значение эл стека
    struct Node *next; //указатель на следующий эл.
}*pNODE, NODE;

typedef struct queue
{
    NODE *beg, *end;
    int len;
}QUEUE, *pQUEUE;

pQUEUE create();
void show(pQUEUE pQ);
float take(pQUEUE pQ);
int isempty(pQUEUE pQ);
void put(pQUEUE pQ, float value);
void clearQueue(pQUEUE pQ);

int main()
{
    pQUEUE pQ = create();
    for (int i = 1; i <= N; i++)
        put(pQ, i);
    show(pQ);
    while(!isempty(pQ))
    {
        take(pQ);
        show(pQ);
    }
    getch();
}

//Function of creating queue
pQUEUE create()
{
    pQUEUE pQ;
    pQ = (pQUEUE)malloc(sizeof(QUEUE));
    pQ->beg=NULL;
    pQ->end=NULL;
    pQ->len=0;
    return pQ;
}

//function of showing queue
void show(pQUEUE pQ)
{
    pNODE p = pQ->beg;
    if (isempty(pQ))
        printf("\nQueue is empty\n");
    while(p)
    {
        printf("%d ", p->val);
        p=p->next;
    }
    printf("\n");
}

//function of validating queue on empty
int isempty(pQUEUE pQ)
{
    if (pQ->beg==NULL)
        return 1;
    return 0;
}

//function of adding elements in queue
void put(pQUEUE pQ, float value)
{
    pNODE pn;
    pn = (pNODE)malloc(sizeof(NODE));
    pn->next = NULL;
    pn->val = value;
    if (pQ->end != NULL)
        pQ->end->next = pn;
    else
        pQ->beg = pn;
    pQ->end = pn;
    pQ->len++;
}

//function of clearing queue
void clearQueue(pQUEUE pQ)
{
    while(!isempty(pQ))
        take(pQ);
    free(pQ);
}

//function of taking queue
float take(pQUEUE pQ)
{
    pNODE p = pQ->beg;
    float c = p->val;
    pQ->beg = p->next;
    free(p);
    pQ->len--;
    return c;
}
